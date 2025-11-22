#include <iostream>
#include <CL/sycl.hpp>

using std::cout ;
using std::endl ;
using namespace sycl ;

int main() 
{
	int i ;
	int const n = 10 ;
	int *A, *B, *C ;

	queue Q(cpu_selector{});

	A = (int *)malloc(sizeof(int)*n) ;
	B = (int *)malloc(sizeof(int)*n) ;
	C = (int *)malloc(sizeof(int)*n) ;

	for(i = 0 ; i < n ; i++) {
		A[i] = 90 ;
		B[i] = 10 ;
	}
			
	buffer<int, 1> buff_a(A, range(n)) ;
	buffer<int, 1> buff_b(B, range(n)) ;
	buffer<int, 1> buff_c(C, range(n)) ;

	Q.submit([&] (handler &cgh){

		auto acc_A = buff_a.get_access<sycl::access::mode::read>(cgh) ;	
		auto acc_B = buff_b.get_access<sycl::access::mode::read>(cgh) ;	
		auto acc_C = buff_c.get_access<sycl::access::mode::write>(cgh) ;	

		cgh.parallel_for(range<1>(n), [=](id<1> idx){
			acc_C[idx] = acc_A[idx] + acc_B[idx] ;
		}) ;

	}).wait() ;
	
	for(i = 0 ; i < n ; i++){
		cout << C[i] << " " ;
	}
	cout << std::endl ;

}

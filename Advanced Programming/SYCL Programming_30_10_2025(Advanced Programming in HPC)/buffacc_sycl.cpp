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

	for(i = 0 ; i < n ; i++) {
		A[i] = 90 ;
	}
			
	buffer<int, 1> buff_a((int *)A, range(n)) ;

	Q.submit([&] (handler &cgh){

		auto acc_A = buff_a.get_access<sycl::access::mode::read_write>(cgh) ;

		cgh.parallel_for(range<1>(n), [=](id<1> idx){
			acc_A[idx] += 10 ;
		}) ;

	}).wait() ;

	for(i = 0 ; i < n ; i++){
		cout << A[i] << " " ; 
	}
	cout << std::endl ;

}

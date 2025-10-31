
#include <iostream>
#include <CL/sycl.hpp>

using std::cout ;
using namespace sycl ;

class scalar_add ;
int scalar_vec_usm(int, int) ;

int main() {

int a = 90 ;
int b = 10 ;
int c = 0 ;

c = scalar_vec_usm(a, b) ;

cout << "The scalar addition of two variables is: [ " << c << " ]" << std::endl ;

return 0 ;
}

int scalar_vec_usm(int a, int b) {

int res = 0 ;
//queue deviceQueue = queue queue_obj{gpu_selector_v} ;
//auto deviceQueue = queue queue_obj{gpu_selector_v} ;
queue deviceQueue{cpu_selector_v} ;

int *dev_A = malloc_device<int>(1, deviceQueue) ;
int *dev_B = malloc_device<int>(1, deviceQueue) ;
int *dev_C = malloc_device<int>(1, deviceQueue) ;

deviceQueue.memcpy(dev_A, &a, 1 * sizeof(int)).wait() ;
deviceQueue.memcpy(dev_B, &b, 1 * sizeof(int)).wait() ;

deviceQueue.submit([&] (handler &cgh) {
	cgh.single_task<scalar_add>([=]() {
		dev_C[0] = dev_A[0] + dev_B[0] ;
	}) ;
}) ;
deviceQueue.wait() ;

deviceQueue.memcpy(&res, dev_C, 1 * sizeof(int)).wait() ;

free(dev_A, deviceQueue) ;
free(dev_B, deviceQueue) ;
free(dev_C, deviceQueue) ;

return res ;
}

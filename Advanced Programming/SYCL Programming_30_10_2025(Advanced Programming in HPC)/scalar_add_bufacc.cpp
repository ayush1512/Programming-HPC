
#include <iostream>
#include <CL/sycl.hpp>

using std::cout ;
using namespace sycl ;

class scalar_add_bufacc ;
int scalar_add(int, int) ;

int main() {
int a = 90 ;
int b = 40 ;
int c = 0 ;

c = scalar_add(a, b) ;

cout << "The addition of two variables is: [ " 
<< c << " ]" << std::endl ;

return 0 ;
}

int scalar_add(int a, int b) {
int res = 0 ;

queue hostQueue{cpu_selector_v} ;

buffer bufA{&a, range{1}} ;
buffer bufB{&b, range{1}} ;
buffer bufC{&res, range{1}} ;

hostQueue.submit([&](handler &cgh) {
	accessor accA = accessor{bufA, cgh, read_only} ;
	accessor accB = accessor{bufB, cgh, read_only} ;
	accessor accC = accessor{bufC, cgh, read_write} ;
	cgh.single_task<scalar_add_bufacc>([=](){
		accC[0] = accA[0] + accB[0] ;
	}) ;
}) ; 
hostQueue.wait() ;

return res ;
}

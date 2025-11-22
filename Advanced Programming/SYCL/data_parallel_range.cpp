
#include <iostream>
#include <CL/sycl.hpp>

using std::cout ;
using namespace sycl ;

class ElementSquaringKernel ;
void range_sample() ;

int main() {

range_sample() ;

return 0 ;
}

void range_sample() {

const size_t N = 10000 ;

std::vector<int> a(N) ;
std::vector<long long> b(N) ;

for(int i = 0 ; i < N ; i++) {
a[i] = i ; 
}

try {

queue defaultQueue(default_selector_v) ;

cout << "Running on device: " 
     << defaultQueue.get_device().get_info<info::device::name>() 
     << std::endl ;
cout << "Vendor info: " 
     << defaultQueue.get_device().get_info<info::device::vendor>() 
     << std::endl ;

buffer<int, 1> bufA(a.data(), range<1>(N)) ;
buffer<long long, 1> bufB(b.data(), range<1>(N)) ;

defaultQueue.submit([&](handler &cgh) {

accessor accA = bufA.get_access<access::mode::read>(cgh) ;
accessor accB = bufB.get_access<access::mode::write>(cgh) ;

cgh.parallel_for<ElementSquaringKernel>(range<1>(N), [=](id<1> idx) {
accB[idx] = static_cast<long long>(accA[idx]) * accA[idx] ;
});
}).wait();

cout << "Verify result" << std::endl ;
for(int i = 0 ; i < N ; i++) {
cout << "b[ " << i << " ] = " << b[i] << std::endl ;
}

} catch (const exception &e){
std::cerr << "SYCL Error: " << e.what() << std::endl ;
}

}




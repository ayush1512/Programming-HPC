
#include <iostream>
#include <CL/sycl.hpp>

using std::cout ;
using namespace sycl ;

class ElementSquaringKernel ;
void nd_range_sample() ;

int main() {

nd_range_sample() ;

return 0 ;
}

void nd_range_sample() {

const size_t dataSize = 1024 ;
const size_t workGroupSize = 128 ;

std::vector<int> a(dataSize) ;
std::vector<long long> b(dataSize) ;

for(int i = 0 ; i < dataSize ; i++) {
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

buffer<int, 1> bufA(a.data(), range<1>(dataSize)) ;
buffer<long long, 1> bufB(b.data(), range<1>(dataSize)) ;

defaultQueue.submit([&](handler &cgh) {

accessor accA = bufA.get_access<access::mode::read>(cgh) ;
accessor accB = bufB.get_access<access::mode::write>(cgh) ;

cgh.parallel_for<ElementSquaringKernel>(nd_range<1>(dataSize, workGroupSize), [=](nd_item<1> itm) {
id idx = itm.get_global_id() ;
accB[idx] = static_cast<long long>(accA[idx]) * accA[idx] ;
});
}).wait();

cout << "Verify result" << std::endl ;
for(int i = 0 ; i < dataSize ; i++) {
cout << "b[ " << i << " ] = " << b[i] << std::endl ;
}

} catch (const exception &e){
std::cerr << "SYCL Error: " << e.what() << std::endl ;
}

}




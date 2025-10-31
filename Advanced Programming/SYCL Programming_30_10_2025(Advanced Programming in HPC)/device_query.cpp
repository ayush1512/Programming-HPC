
#include <iostream>
#include <CL/sycl.hpp>

using std::cout ;
using namespace sycl ;

class scalar_add_bufacc ;
int scalar_add(int, int) ;

int main() {
	int a = 75 ;
	int b = 85 ;
	int c = 0 ;

	c = scalar_add(a, b) ;

	cout << std::endl ;
	cout << "The output is: [ " << c << " ]\n" << std::endl ;

	return 0 ;
}

int custom_cpu_selector1(const device &dev) {

	if(dev.has(aspect::cpu)) {
		auto VendorName = dev.get_info<info::device::vendor>() ;
		if(VendorName.find("Intel") != std::string::npos) {
			return 1 ;		
		}
	}
	return -1 ;
}

int scalar_add(int a, int b) {
	int res = 0 ;

	queue deviceQueue{custom_cpu_selector1} ;
	
	auto device_info   = deviceQueue.get_device().get_info<info::device::name>() ;
	auto device_vendor = deviceQueue.get_device().get_info<info::device::vendor>() ;
	
	cout << std::endl ;
	cout << "Running on device: [ " << device_info << " ]" << std::endl ;
	cout << "The Vendor is: [ " << device_vendor << " ]" << std::endl ;

	buffer<int, 1> bufA{&a, range(1)} ;
	buffer<int, 1> bufB{&b, range(1)} ;
	buffer<int, 1> bufC{&res, range(1)} ;

	deviceQueue.submit([&](handler &cgh){
			accessor accA = accessor{bufA, cgh, read_only} ;
			accessor accB = accessor{bufB, cgh, read_only} ;
			accessor accC = accessor{bufC, cgh, read_write} ;
			cgh.single_task<scalar_add_bufacc>([=](){
					accC[0] = accA[0] + accB[0] ;
					}) ;
			}).wait() ;

	return res ;
}




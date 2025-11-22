#include <sycl/sycl.hpp>
 	
using std::cout ;
using std::endl ;
using namespace sycl ;

int main()
{
	for (auto platform : sycl::platform::get_platforms())
	{
		cout << "Platform : " << platform.get_info<sycl::info::platform::name>() << std::endl;
	
		for (auto device : platform.get_devices())
		{
			cout << "Device : " << device.get_info<sycl::info::device::name>() << std::endl;
		}
	}

}


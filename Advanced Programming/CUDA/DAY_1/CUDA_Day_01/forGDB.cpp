
// header-part
#include <iostream>
using namespace std;


// -- Lib --
//  --- CUDA kernel-side => GPU-side
//  below is normal C++ code
//
void gfun(int argx, int argy){
	cout << " Inside gfun...\n";
}


// -- app/client --
//  --- CuDa Core / host=> CPU-side
int main(){
	int li = 10, lj = 20;

	cout << "---- Main start ----\n";
	gfun( li, lj);
	cout << "---- Main end ----\n";
}


// header-part
#include <stdio.h>


// -- Lib --
//  --- CUDA kernel-side => GPU-side
//  below is normal C code
//
void gfun(int argx, int argy){
	printf(" Inside gfun...\n");
}


// -- app/client --
//  --- CuDa Core / host=> CPU-side
int main(){
	int li = 10, lj = 20;

	printf("---- Main start ----\n");
	gfun( li, lj);
	printf("---- Main end ----\n");
}

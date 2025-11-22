
// header-part
//#include <iostream>
//using namespace std;


//const int gi = 10; // Data-segment::RO
//int gi = 10; // Data-segment::Initialized::RW
//int gi; // Data-segment::UnInitialized::BSS

// -- Lib --
//  below is normal C++ code
void gfun(int argx, int argy)
{ // prologue
	int lm = -5, ln = -6;

	// use argx, argy, lm, ln
	argx = lm + ln - argy;

//	cout << " Inside gfun...\n";
} // Epilogue


// -- app/client --
int main(){
// offset(locals) => - (sum_of_sizes_of_locals_declared_before + it's_size )
// offset (li) => - ( 0 + 4) => -4
// offset (lj) => - ( 4 + 4) => -8
	//const int lci = 5; // User-Stack // const is just qualifier
	int li = 10, lj = 20;
	/*
 * 		sub esp, sizeof(locals)
 * 		mov [li], 10 => ebp + offset(li) => 1000 + (-4) => -996
 * 		mov [lj], 20 => ebp + offset(lj) => 1000 + (-8) => -992
 * 	*/

//	cout << "---- Main start ----\n";
	gfun( li, lj);
	/*
 *		// pass arg
 *
 *		call gfun
 * 	*/
//	cout << "---- Main end ----\n";
}

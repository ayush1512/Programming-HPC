#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


int main(){

	pid_t pid = fork();

	if( 0 == pid) { // child
		int child_value = 1234;
		std::cout<<" Child: child_value = "<< child_value <<"\n";
		_exit(0);
	} else { // Parent
		int parent_value = 5678;
		wait(nullptr);
		std::cout<<" Parent: Parent_value = "<< parent_value <<"\n";
	}	
	return 0;
}


#include <iostream>
#include <pthread.h>
#include <unistd.h>
//using namespace std;

int gCount = 0;
// Data-race problem:
// Avoid:
//   1. Don't use globals.
//   2. Use synchronization methods (lock, mutex, binary-semaphore, unique_lock with lock-deffered-flag(to avoid deadlock)...
//   3. Good interface design.
//   4. HAve resource and lock binded always to-gether...

// worker function for threads to start 
void * worker( void * args){
	int id = *( (unsigned int *)args);

	for ( int i=0; i<40000; i++){
		//std::cout << " Thread : " << id <<" in Iteration #: "<< i <<"\n";
		gCount ++;
		//sleep(1);
	}

	return nullptr;
}


// main-thread => main-program/process
int main(){
	pthread_t t1, t2;
	int id1 = 100, id2 = 200;

	std::cout<<" --- Main-thread-started ---\n";

	std::cout<<" Main<before threads-creations>: gCount = "<< gCount <<"\n";
	pthread_create( &t1, nullptr, worker, &id1);
	pthread_create( &t2, nullptr, worker, &id2);
	
	std::cout<<"  ---- Main thread waiting for child threads to complete.\n" ;

	pthread_join(t1, nullptr);
	pthread_join(t2, nullptr);
	std::cout<<" Main<after threads-execution><expected 80000 value>: gCount = "<< gCount <<"\n";
	std::cout<<" --- Main-thread-ended ---\n";
	return 0;
}


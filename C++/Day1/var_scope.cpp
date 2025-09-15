#include <iostream>

//data segment
int globalVariable = 10; // Global variable 'a' initialized to 10

int main(){
    //stack segment
    int stackVar = 5;
    //heap segment
    int* heapVar = new int(10); //    
    std::cout << "Value of Stack Var: " << stackVar <<" " << &stackVar <<  std::endl;
    std::cout << "Value of Heap Var: " << *heapVar << " "  << heapVar <<std::endl;
    std::cout << "Value of Global Var: " << globalVariable << " "  << &globalVariable<< std::endl;
    
    return 0;
}

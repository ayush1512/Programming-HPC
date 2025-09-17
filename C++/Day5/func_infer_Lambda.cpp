#include <iostream>

using namespace std;


void display(int x) {
    cout << "Value: " << x << endl;
}

void displayFunc(int x, void (*funcPtr)(int)) {
    cout << "Value from function pointer: " << x << endl;
    funcPtr(x);
}

class A{
    int data;
    void* operator new(size_t size) = delete; // Prevent dynamic allocation
    public:
    A(int val): data(val) {}
};

int main() {

    // int *a = new int[10]; // allocate an array of 10 integers

    display(5); // call the function with an integer argument

    void (*funcPtr)(int) = display; // function pointer to the display function
    funcPtr(10); // call the function via the pointer
    //display(10);

   displayFunc(15, funcPtr);

   //Type inference with auto keyword
   auto a = 10;
   auto b = 20.5;
   auto c = "Hello, World!";

    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

    // Using lambda expressions
    auto lambda = [&](int x) { cout << "Lambda Value: " << x << endl; };

    // returnType function(int x){
    //     cout << "Function Value: " << x << endl;
    // }
    lambda(25);

   A obj(100);
//    A* obj2 = new A(200); // Error: dynamic allocation is prevented


    // delete[] a; // correctly deallocate the array

    return 0;
}
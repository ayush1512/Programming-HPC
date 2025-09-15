#include <iostream>

using namespace std;

void greet();
int add(int a, int b);

inline int add(int a){ return a*a; } //inline function

int main(){
    int result = add(2, 3);
    int square = add(5); //inline function call
    // cout<<"Result: "<<result<<endl;
    cout<<"Square: "<<square<<endl;
    // greet();
    return 1;
}

// returnType functionName(parameters){
//     //body
// }

// void hello(){};
// void greet(int a, int b);
// int add(int a, int b);

int add(int a, int b){
    cout<<"Sum: "<<a+b<<endl;
    return a + b;
}

void greet(){
    cout<<"Hello, Good Morning!"<<endl;
}

int factorial(int n){
    if(n==0) return 1;
    return n * factorial(n-1);
}
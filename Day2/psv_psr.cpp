#include <iostream>

using namespace std;

int add(int a, int b){ // pass by value
    a++; // changes in local copy
    b++; // changes in local copy
    return a + b;
}

int add1(int &a, int &b){ // pass by reference
    a++;
    b++;
    return a + b;
}

int main(){
    int a = 5;
    int b = 10;

    int* a1 = new int(10);
    int* b1 = new int(20);
    
    int result = add(a, b);
    int result1 = add1(*a1, *b1);
    
    cout<<"a: "<<a<<", b: "<<b<<endl; // original values unchanged -> pass by value
    cout<<"a1: "<<*a1<<", b1: "<<*b1<<endl; // original values changed -> pass by reference

    cout << "The sum is: " << result << endl;
    cout << "The sum is: " << result1 << endl;
    delete a1;
    delete b1;
    return 0;
}
#include <iostream>
using namespace std;


//-----Simple Friend Function Example-----

// class A {
//     int data;
// public:
//     friend void display(const A& a); // Friend function declaration
// };

//-----Friend Function with Complex Class Example-----
// class Complex {
//     int real, imag;
// public:
//     Complex(int r = 0, int i = 0) : real(r), imag(i) {}

//     void display() const {
//         cout << real << " + " << imag << "i" << endl;
//     }

//     friend void add(Complex c1, Complex c2); // Friend function declaration
// };

//-----Friend Function with Two Different Classes Example-----
// class C; // Forward declaration

// class B {
//     int data;
// public:
//     B(int d = 0) : data(d) {}

//     friend void sumOfTwoClasses(B b1, C c1); // Friend function declaration
// };

// class C {
//     int data;
// public:
//     C(int d = 0) : data(d) {}

//     friend void sumOfTwoClasses(B b1, C c1); // Friend function declaration
// };


//---Friend Function with Member Function of another class---
// class X; // Forward declaration

// class Y{
//     int y;
// public:
//     Y(int d = 0) : y(d) {}

//     void displayX(X& x);
// };

// class X{
//     int x;
// public:
//     X(int d = 0) : x(d) {}

//     friend void Y::displayX(X& x); // Friend function declaration
// };

//---Friend Class Example---
class A{
    int x;
    public:
    A(int d = 0) : x(d) {} 
    friend class B; // B is a friend of A
};

class B{
    int y;
public:
    void display(const A& a) {
        cout << "A::x = " << a.x << endl; // Accessing private member of class A
        cout << "B::y = " << y << endl;
    }
};

class C : public B{
    int z;
public:
    C(int d = 0) : z(d) {}
    void display() {
        // cout << "C::z = " << x << endl; // Error: x is not accessible here
    }
};

// Friend function definition -> for class A
// void display(const A& a){
//     cout << a.data << endl; // Accessing private member of class A
// }

// Friend function definition -> for class Complex
// void add(Complex c1, Complex c2) {
//     cout << "Sum: " << (c1.real + c2.real) << " + " << (c1.imag + c2.imag) << "i" << endl;
// }

// Friend function definition -> for class B & C addition
// void sumOfTwoClasses(B b1, C c1){
//     cout << "Sum of B and C: " << (b1.data + c1.data) << endl;
// }

// Friend function definition -> for class X & Y member function
// void Y::displayX(X& x) {
//     cout << "Value of x: " << x.x << endl; // Accessing private member of class X
// }

int main() {
    // Simple Friend Function 
    // A a;
    // display(a);

    // Complex Number Addition using Friend Function
    // Complex c(5, 10);
    // Complex d(3, 4);
    // c.display();
    // d.display();
    // add(c, d);


    // Sum of Two Different Classes using Friend Function
    // B b1(5);
    // C c1(10);
    // sumOfTwoClasses(b1, c1);

    // Member Function of one class accessing private members of another class using Friend Function
    // X x(42);
    // Y y(100);
    // y.displayX(x); // Accessing private member of class X through Y's member function

    return 0;
}
#include <iostream>

using namespace std;

// Function Overriding -> same function name in base and derived class
// Runtime Polymorphism
// Late Binding -> decision is made at runtime


class Base{
    public:
    void show(){
        cout<<"Base class show function called!"<<endl;
    }
};

class Derived : public Base{
    public:
    void show(){
        cout<<"Derived class show function called!"<<endl;
    }
};

int main(){
    Base b1;
    b1.show();

    Derived d1;
    d1.show();

    Base* baseptr; // base class pointer
    baseptr = &d1; // pointing to derived class object
    baseptr->show(); // Base class show function called! -> early binding

    return 0;
}
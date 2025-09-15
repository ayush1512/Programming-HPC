#include <iostream>

using namespace std;

// Interface
class A{

    public:
    virtual void display() = 0; // pure virtual function

};


// abstract class
class Base{
    public:
        // Making show() a virtual function
        virtual void show(){
            cout << "Base class show function called" << endl;
        } 

        void display(){
            cout << "Base class display function called" << endl;
        }
};

class Derived: public Base{
    public:
        void show() override {
            cout << "Derived class show function called" << endl;
        }
};

int main(){
    Base* b;
    Derived d;
    b = &d;
    b->show(); // Calls Derived class show function
    return 0;
}
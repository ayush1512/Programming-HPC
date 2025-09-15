#include <iostream>

using namespace std;

class A{
    public:
    //default constructor
    A(){
        cout<<"Constructor A"<<endl;
    };
    //parameterized constructor
    A(int x){
        cout<<"Constructor A with arguments: "<<x<<endl;
    }
    //copy constructor - to create a copy of object
    A(A &obj){
        cout<<"Copy Constructor A"<<endl;
    }

    ~A(){
        cout<<"Destructor A"<<endl;
    }

    void display(){
        cout<<"Display A"<<endl;
    }
};

class B : public A{
    public:
    B(){
        cout<<"Constructor B"<<endl;
    };

    ~B(){
        cout<<"Destructor B"<<endl;
    }
};

int main(){
    // A a1;
    // A a2(10);
    B b1;
    // A a3(a2);
    // b1.display();
    return 0;
}
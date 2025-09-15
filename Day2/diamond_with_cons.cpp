#include <iostream>

using namespace std;

class A{
    public:

    A(){
        cout<<"Constructor A"<<endl;
    };

    void funcA(){
        cout<<"Function A"<<endl;
    }

    ~A(){
        cout<<"Destructor A"<<endl;
    }
};

class B : virtual public A{ // to avoid ambiguity
    public:
    //funcA()

    B(){
        cout<<"Constructor B"<<endl;
    };

    void funcB(){
        cout<<"Function B"<<endl;
    }

    ~B(){
        cout<<"Destructor B"<<endl;
    }
}; 

class C : virtual public A{
    public:
    //funcA()

    C(){
        cout<<"Constructor C"<<endl;
    };

    void funcC(){
        cout<<"Function C"<<endl;
    }

    ~C(){
        cout<<"Destructor C"<<endl;
    }
};

class D : public B, public C{
    public:

    D(){
        cout<<"Constructor D"<<endl;
    };

    void funcD(){
        cout<<"Function D"<<endl;
    }

    ~D(){
        cout<<"Destructor D"<<endl;
    }
};


int main(){
    D d1;
    d1.funcA(); // Ambiguity
    d1.funcB();
    d1.funcC();
    d1.funcD();
    return 0;
}
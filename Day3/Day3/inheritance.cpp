#include <iostream>

/* 
=====================================================================|
|           Access of Base Members in Derived Class (C++)            |
=====================================================================|
| Inheritance  |  public member  | protected member | private member |
|--------------|-----------------|-----------------|---------------- |
| public       |   public        |   protected      |   not inherited|
| protected    |   protected     |   protected      |   not inherited|
| private      |   private       |   private        |   not inherited|
=====================================================================|
Notes:
- "not inherited" means the derived class cannot access the base's private members directly.
- The table shows how the access specifier of base class members changes in the derived class.
*/

#include <iostream>

using namespace std;

// Base class
class A {
    int a = 10; // private by default

protected:
    int b = 20; // protected member

public:
    int c = 30; // public member

    void showMembers() {
        cout << "A::a (private): Not accessible outside A" << endl;
        cout << "A::b (protected): " << b << endl;
        cout << "A::c (public): " << c << endl;
    }
};

// Public inheritance: public/protected members keep their access
class B : public A {
public:
    void show() {
        // cout << "a: " << a << endl; // Error: 'a' is private
        cout << "B (public A): b (protected): " << b << endl; // Accessible
        cout << "B (public A): c (public): " << c << endl; // Accessible
    }
};

// Protected inheritance: public/protected members become protected
class C : protected B {
public:
    void show() {
        // cout << "a: " << a << endl; // Error: 'a' is private
        cout << "C (protected B): b (protected): " << b << endl; // Accessible
        cout << "C (protected B): c (protected): " << c << endl; // Accessible, but now protected
    }
};

// Demonstrate access in further derived class
class D : public C {
public:
    void show() {
        // cout << "a: " << a << endl; // Error: 'a' is private
        cout << "D (public C): b (protected): " << b << endl; // Accessible here
        cout << "D (public C): c (protected): " << c << endl; // Accessible here
    }
};

// Private inheritance: public/protected members become private
class E : private A {
public:
    void show() {
        // cout << "a: " << a << endl; // Error: 'a' is private
        cout << "E (private A): b (private): " << b << endl; // Accessible here
        cout << "E (private A): c (private): " << c << endl; // Accessible here
    }
};

int main() {
    cout << "--- Base class A ---" << endl;
    A objA;
    objA.showMembers();
    // cout << objA.a << endl; // Error: private
    // cout << objA.b << endl; // Error: protected
    cout << "A::c (public): " << objA.c << endl; // OK

    cout << "\n--- Public inheritance (B) ---" << endl;
    B objB;
    objB.show();
    cout << "B::c (public): " << objB.c << endl; // OK

    cout << "\n--- Protected inheritance (C) ---" << endl;
    C objC;
    objC.show();
    // objC.c; // Error: c is protected in C

    cout << "\n--- Private inheritance (E) ---" << endl;
    E objE;
    objE.show();
    // objE.c; // Error: c is private in E

    cout << "\n--- Derived from protected (D) ---" << endl;
    D objD;
    objD.show();
    // objD.c; // Error: c is protected in D

    return 0;
}
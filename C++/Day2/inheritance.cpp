// Inheritance -> acquiring properties and behaviors from a parent class
// Types of Inheritance
// 1. Single Inheritance
// 2. Multilevel Inheritance
// 3. Multiple Inheritance
// 4. Hierarchical Inheritance
// 5. Hybrid Inheritance

#include <iostream>
using namespace std;

// //1. Single Inheritance
// class LivingBeing{
//     public:
//     void breathe(){
//         cout<<"I can breathe!"<<endl;
//     }
// };

// class Human : public LivingBeing{
//     public:
//     void speak(){
//         cout<<"I can speak!"<<endl;
//     }
// };
// //---------------------------------------------------------------------------------------
// //2. Multilevel Inheritance
// class Animal{
//     public:
//     void eat(){
//         cout<<"I can eat!"<<endl;
//     }
// };

// class Mammal : public Animal{
//     public:
//     //eat()
//     void walk(){
//         cout<<"I can walk!"<<endl;
//     }
// };

// class Dog : public Mammal{
//     public:
//     //eat()
//     //walk()

//     void bark(){
//         cout<<"I can bark!"<<endl;
//     }
// };
// //---------------------------------------------------------------------------------------
// //3. Multiple Inheritance
// class LivingBeing{
//     public:
//     void breathe(){
//         cout<<"I can breathe!"<<endl;
//     }
// };

// class Mammal{
//     public:
//     void walk(){
//         cout<<"I can walk!"<<endl;
//     }
// };

// class Dog : public LivingBeing, public Mammal{
//     public:
//     //walk()
//     void bark(){
//         cout<<"I can bark!"<<endl;
//     }
// };

// //---------------------------------------------------------------------------------------
// //4. Hierarchical Inheritance
// class Animal{
//     public:
//     void eat(){
//         cout<<"I can eat!"<<endl;
//     }
// };

// class Dog : public Animal{
//     public:
//     //eat()
//     void bark(){
//         cout<<"I can bark!"<<endl;
//     }
// };

// class Cat : public Animal{
//     public:
//     //eat()
//     void meow(){
//         cout<<"I can meow!"<<endl;
//     }
// };

//---------------------------------------------------------------------------------------
//5. Hybrid Inheritance

class A{
    public:
    void funcA(){
        cout<<"Function A"<<endl;
    }
};

class B : virtual  public A{ // to avoid ambiguity
    public:
    //funcA()
    void funcB(){
        cout<<"Function B"<<endl;
    }
};

class C : virtual public A{
    public:
    //funcA()
    void funcC(){
        cout<<"Function C"<<endl;
    }
};

class D : public B, public C{
    public:
    //funcB(), funcC(), funcA() -> Ambiguity
    void funcD(){
        cout<<"Function D"<<endl;
    }
};

int main(){
    // Human h1;
    // h1.breathe(); // inherited from LivingBeing class
    // h1.speak();

    // Dog d1;
    // // d1.eat();    // inherited from Animal class
    // // d1.walk();   // inherited from Mammal class
    // d1.bark();

    D d1;
    d1.funcA(); // Ambiguity
    d1.funcB();
    d1.funcC();
    d1.funcD();
    return 0;
}

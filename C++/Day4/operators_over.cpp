#include <iostream>

using namespace std;

// 1. Unary operator overloading
// 2. Binary operator overloading 
// 3. Ternary operator overloading is not possible
// 4. Assignment operator overloading =
// 5. Relational operator overloading <, >, <=, >=, ==, != 
// 6. Arithmetic operator overloading +, -, *, /, %

class A {
    int a;
public:
    A() : a(0) {} // Constructor to initialize 'a' to 0
    A(int val) : a(val) {} // Constructor to initialize 'a' to val

    //Copy constructor
    A(const A& obj) : a(obj.a) {
        cout << "Copy constructor called: " << a << endl;
    }

    // Unary operator overloading
    // Prefix
    A& operator++() {
        ++a;
        cout << "Prefix increment: " << a << endl;
        return *this;
    }

    // Postfix
    A operator++(int) {
        A temp = *this; // Create a copy of the current state
        a++;
        cout << "Postfix increment: " << a << endl;
        return temp; // Return the old state
    }

    //Binary operator overloading
    A operator+(const A& obj) {
        A temp;
        temp.a = this->a + obj.a;
        cout << "Binary + operator: " << temp.a << endl;
        return temp;
    }

    //Assignment operator overloading
    // A& operator=(const A& obj) {
    //     if (this != &obj) { // Self-assignment check
    //         this->a = obj.a;
    //     }
    //     cout << "Assignment operator: " << a << endl;
    //     return *this;
    // }

    // Relational operator overloading
    bool operator==(const A& obj) {
        return this->a == obj.a;
    }

    // Stream insertion operator overloading (for output)
    friend ostream& operator<<(ostream& os, const A& obj) {
        os << obj.a;
        return os;
    }

    // Stream extraction operator overloading (for input)
    friend istream& operator>>(istream& is, A& obj) {
        is >> obj.a;
        return is;
    }

    //Copy & swap idioms
    A& operator=(A obj) { // Pass by value to create a copy
        cout << "Assignment operator (copy & swap): "<< endl;
        swap(a, obj.a); // Swap the contents
        return *this;
    }

    //conversion operator
    operator int() const {
        return a;
    }

    // Function to display for object the value of 'a' 
    void display() {
        cout << "Value of a: " << a << endl;
    }

};


int main() {
    
    A a1 = A(10); //Object of class A 

    // a1++; // Postfix increment -> calls operator++(int)
    // ++a1; // Prefix increment -> calls operator++()

    A a2 = A(20);
    A a3 = A(30);
    a1 + a2 + a3; // Binary + operator -> calls operator+(const A& obj)
    //a1.add(a2); // Equivalent to a1.operator+(a2)


    A a4;
    // a4 = a1; // Assignment operator -> calls operator=(const A& obj)
    a4.display();

    cout << ((a1 == a4) ? "Identical" : "Different") << endl; // Relational operator -> calls operator==(const A& obj)
    cout << ((a1 == a2) ? "Identical" : "Different") << endl; // Relational operator -> calls operator==(const A& obj)

    cout << "Value of a1: " << a1 << endl; // Stream insertion operator -> calls operator<<(ostream& os, const A& obj)

    A a5;
    cout << "Enter value for a5: ";
    cin >> a5; // Stream extraction operator -> calls operator>>(istream& is, A& obj)

    A a6;
    a6 = a5; // Assignment operator (copy & swap) -> calls operator=(A obj)
    cout << "Value of a6 (copy of a5) with copy & swap: " << a6 << endl;

    A a7;
    a7 = A(a6); // Copy constructor called -> if not defined, default copy constructor is used
    cout << "Value of a7 (copy of a6) with CC: " << a7 << endl;

    int intValue = a7; // Conversion operator -> calls operator int()
    cout << "Integer value of a7: " << intValue << endl;

    return 0;
}
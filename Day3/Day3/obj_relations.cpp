#include <iostream>

using namespace std;

//Association
class Student{
    public:
        string name;
        int age;

        Student(string n, int a): name(n), age(a) {
        }
}; // Student class ends here

class Teacher{
    public:
        string name;
        int age;

        Teacher(string n, int a): name(n), age(a) {}

        void teachStudent(Student &s){
            cout << "Teacher " << name << " is teaching student " << s.name << endl;
        }
};

// Aggregation
// class Engine{
//     public:
//         string type;

//         Engine(string t): type(t) {}
// };
// class Car{
//     public:
//         string model;
//         int year;
//         // Aggregation
//         Engine* engine; // Pointer to Engine 

//         Car(string m, int y): model(m), year(y), engine(nullptr) {}

//         void setEngine(Engine &e){
//             engine = &e; // Set the engine
//             cout << "Car " << model << " has engine of type " << engine->type << endl;
//         }
// };

// Composition
class Engine{
    public:
        string type;

        Engine(string t): type(t) {}
};
class Car{
    public:
        string model;
        int year;
        // Composition
        Engine engine; // Engine object

        Car(string m, int y): model(m), year(y), engine("V8") {} // Initialize engine in constructor

        void display(){
            cout << "Car " << model << " has engine of type " << engine.type << endl;
        }
};



class Printer{
    public:
        void printMessage(const string &msg){
            cout << msg << endl;
        }
};

class Computer{
    public:
        void print(Printer &printer, const string &msg){
            printer.printMessage(msg);
        }
};



int main(){
    Student s1("Ramlal", 20);
    Teacher t1("Mr. Shamlal", 40);
    t1.teachStudent(s1); // Association: Teacher teaches Student


    //Aggregation
    // Car car1("Toyota", 2020);
    // Engine engine1("V6");
    // car1.setEngine(engine1); // Aggregation: Car has an Engine

    //Composition
    Car car2("Ford", 2021);
    car2.display(); // Composition: Car has an Engine

    Printer printer; // Printer instance
    Computer computer; // Computer instance
    computer.print(printer, "Hello from Computer!"); // Dependency: Computer uses Printer

    return 0;
}
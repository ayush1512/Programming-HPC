#include <iostream>
#include <cstring> // For strcpy and strlen

using namespace std;

class Student{
    public:
        char* name;
        int age;

        //Shallow Copy constructor
         Student(const char* n, int a): age(a) {
             name = new char[strlen(n) + 1];
             strcpy(name, n);
         }

        // Deep Copy constructor
        Student(const Student &s): age(s.age) {
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
        }

};

int main(){
    Student s1("Alice", 20); // Normal constructor
    Student s2 = s1; // Deep copy constructor
    cout << "Student 1: " << s1.name << ", Age: " << s1.age << endl;
    cout << "Student 2: " << s2.name << ", Age: " << s2.age << endl;

    Student s3("Bob", 22);
    s3 = s1; // Default shallow copy assignment
    cout << "Student 3: " << s3.name << ", Age: " << s3.age << endl;
    
    s3.name[0] = 'C'; // Modifying s3's name
    cout << "After modifying s3's name:" << endl;
    cout << "Student 1: " << s1.name << ", Age: " << s1.age << endl;
    cout << "Student 2: " << s2.name << ", Age: " << s2.age << endl;
    cout << "Student 3: " << s3.name << ", Age: " << s3.age << endl;
    return 0;
}
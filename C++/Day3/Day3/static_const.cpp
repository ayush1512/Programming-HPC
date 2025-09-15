#include <iostream>

using namespace std;

class Student {
    public:
        const static int studentCount; // Static member to keep track of student count
        string name;
        int age;
        const int id; // Constant member

        // Student(string n, int a): name(n), age(a) {
        //     studentCount++;
        // }

        // Student(string n, int a, int i): name(n), age(a), id(i) {
        //     studentCount++; // Error: for Static member
        // }
        static int getStudentCount() {
            return studentCount;
        }

        void display() const {
            cout << "Name: " << name << ", Age: " << age << ", ID: " << id << endl;
        }
};

// Initialize static member
const int Student::studentCount = 0;

int main() {
    // Student s1("Alice", 20);
    // Student s2("Bob", 22);
    cout << "Total Students: " << Student::getStudentCount() << endl;
    // cout << "Student 1: " << s1.name << ", Age: " << s1.age << ", Total Students: " << Student::getStudentCount() << endl;
    // cout << "Student 2: " << s2.name << ", Age: " << s2.age << ", Total Students: " << Student::getStudentCount() << endl;

    // Student s3("Charlie", 23, 101); 
    // cout << "Student 3: " << s3.name << ", Age: " << s3.age << ", ID: " << s3.id << ", Total Students: " << Student::getStudentCount() << endl;
    // s3.id = 102; // Error: cannot modify a const member
    return 0;
}
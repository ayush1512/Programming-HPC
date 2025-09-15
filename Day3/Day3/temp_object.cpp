#include <iostream>

using namespace std;

class Student{
    public:
        string name;
        int age;

        Student(string n, int a): name(n), age(a) {
        }

        // temp_object method
        Student* func(){
            return new Student("Shil", 20); // Temporary object
        }


}; // Student class ends here

int main(){
    // cout << "Temporary Object Example" << endl;
    
    Student s1("Sunny", 20); // Normal object
    Student* temp = s1.func(); // Get temporary object

    cout << "Temporary Student: " << temp->name << ", Age: " << temp->age << endl;
    
    delete temp; // Clean up temporary object
    
    return 0;
}
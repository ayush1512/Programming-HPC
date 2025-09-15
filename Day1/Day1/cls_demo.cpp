#include <iostream>
using namespace std;

// private -> Accessible in the same class/method/scope only
// public -> Accessible from anywhere
// protected -> Accessible in the same class/method/scope and derived class only

//class
class Person{
    string name;
    int age;

    public:
    void setName(string n){
        name = n;
    }

    void setAge(int a){
        age = a;
    }

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    void display(){
        cout<<"Name: " << name<<" Age: "<<age<<endl;
    }

}; //Person class ends here...

int main(){
    // Person p1;
    // p1.setName("Shil");
    // p1.setAge(25);

    // Person p2;
    // p2.setName("Sandip");
    // p2.setAge(20);

    Person p1, p2;
    string name;
    int age;
    cout<<"Enter name: "<<endl;
    cin>>name;
    cout<<"Enter age: "<<endl;
    cin>>age;

    p1.setName(name);
    p1.setAge(age);

    // p1.display();
    // p2.display();
    return 0;
}

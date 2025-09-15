#include <iostream>

using namespace std;

void display(string name = "Guest"){ // default argument
    cout<<"Hello, "<< name<<endl;
}

//Wrong way to create a function with variable number of arguments
// int add(int args, ...){ // args -> number of arguments{
//     return args + ...; 
// }

// function with variable number of arguments
template<typename... Args> // variadic template -> arguments can be of any type
int add(Args... args){ // args -> number of arguments
    return (args + ...); // to return sum of all arguments
    // return args + ...; // C++11 feature (fold expression)
}

int main(){
    display();
    display("John");
    add(1,2,3,4,5);
    return 0;
}
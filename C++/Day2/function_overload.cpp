#include  <iostream>
using namespace std;

// Polymorphism -> many forms
// 
// function overloading -> same function name with different parameters
int add(int a, int b){
    return a + b;
}

//returnType is excluded in function overloading
// float add(int a, int b){ // parameter are important // ERROR
//     return a + b;
// }

int add(float a, float b){ // different data type
    return a + b;
}

int add(int a, int b, int c){ // different number of parameters
    return a + b + c;
}

int main(){
    
cout<<"Sum int: "<<add(2, 3)<<endl;
cout<<"Sum float: "<<add(2.5f, 3.5f)<<endl;

return 0;
}
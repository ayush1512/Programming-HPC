#include <iostream>

// using namespace std;

namespace MyNamespace {
    void greet() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}

namespace AnotherNamespace {

    class Sample {}; 
    int x = 42;
    void greet() {
        std::cout << "Hello from AnotherNamespace!" << std::endl;
    }
}

// Using the namespaces aliases
namespace MyNS = MyNamespace;

int main() {
    std::cout << "Hello, World!" << std::endl;
    MyNamespace::greet(); // Fully qualified name
    MyNS::greet(); // Using alias
    AnotherNamespace::greet();
    return 0;
}
#include <iostream>
#include <exception>

using namespace std;

void MyTerminateHandler() {
    cerr << "Custom terminate handler called. Program will terminate." << endl;
    exit(1);
}

class ArithmeticException : public exception {
    string message;
public:
    ArithmeticException(const string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return ("ArithmeticException: " + message + " at line " + to_string(__LINE__)).c_str();
    }
};

void divide(int a, int b) {
        if (b == 0) {
            throw ArithmeticException("Division by zero");
        }
        cout << "Result: " << a / b << endl;
}

int main() {
    try {
        // int a = 10;
        // float b = 9.8f;

        // throw a; // Throwing an integer exception
        // throw b; // Throwing a float exception
    } 
    catch (int e) {
        cerr << "Integer exception caught: " << e << endl;
    } 
    catch (float e) {
        cerr << "Float exception caught: " << e << endl;
    }
    catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught" << endl;
    }

    // set_terminate(MyTerminateHandler);
    // int a = 20;
    // throw a;

    int a = 10, b = 0;
    divide(a, b);

    return 0;
}
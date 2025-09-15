#include <iostream>                          // iostream library for input and output
#define PI 3.14                              // for example, Define a constant PI with value 3.14
using namespace std;                         // Use the standard namespace

int main() {                                 // Main function - execution starts here
    int a = 5;                               // Declare an integer variable 'a' and initialize it to 5
    cout << "Enter a number: ";              // Prompt the user to enter a number
    cin >> a;                                // Read the input number and store it in variable 'a'
    cout << "Hello, World! " << a << endl;   // Output "Hello, World!"
    return 0;                                // Return 0 to indicate successful execution
}

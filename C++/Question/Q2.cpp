#include <iostream>
using namespace std;
class Complex
{
private:
    int real;
    int img;

public:
    // Getters
    int getReal() const { return this->real; }
    int getImg() const { return this->img; }

    //Setters
    void setReal(int r){ this->real = r; }
    void setImg(int i){ this->img = i; }
    
    void showData();
    Complex operator+(Complex a)
    {
        Complex tmp;
        tmp.real = this->real + a.real;
        tmp.img = this->img + a.img;
        return tmp;
    }
};
void Complex::showData()
{
    cout << "Real Part: " << this->getReal() << "   Imaginary Part: " << this->getImg() << endl;
}
int main()
{
    Complex c1, c2, c3;
    c1.setReal(10);
    c1.setImg(2);
    c2.setReal(10);
    c2.setReal(3);

    c1.showData();
    cout << "\n";
    c2.showData();
    cout << "\n";
    
    c3 = c1 + c2;
    cout << "After using the overloaded + operator" << endl;
    c3.showData();


}
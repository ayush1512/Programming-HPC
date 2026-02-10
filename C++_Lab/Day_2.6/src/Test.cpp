#include <iostream>
using namespace std;
class Shape
{
public:
	float Area;
	float Perimeter;
	void PrintArea()
	{
		cout<<"Area: "<<this->Area<<endl;
	}
	void PrintPerimeter()
	{
		cout<<"Perimeter: "<<this->Perimeter;
	}
	virtual void CalculateArea()=0;		//Pure Virtual Function, Abstract class
};
class Rectangle: public Shape
{
public:
	float Length;
	float Width;
	void CalculateArea()
	{
		this->Area=this->Length*this->Width;
	}
};
class Circle: public Shape
{
public:
	float Radius;
	void CalculateArea()
	{
		this->Area=3.14*(this->Radius*this->Radius);
	}
};
int main()
{
	Circle c1;
	c1.Radius=30;
	c1.CalculateArea();
	c1.PrintArea();
}
int main1()
{
	Rectangle r1;
	r1.Length=100;
	r1.Width=200;
	r1.CalculateArea();
	r1.PrintArea();
	return 0;
}

#include <iostream>
using namespace std;
class Student
{
public:
	int RollNo;		//Data Member
	char Name[40];
	int Age;
	float Salary;

	void AcceptRecord()		//void AcceptRecord(const Student *this)
	{
		cout<<"Enter RollNo: "<<endl;
		cin>>RollNo;
		cout<<"Enter Name: "<<endl;
		cin>>Name;
		cout<<"Enter Age: "<<endl;
		cin>>Age;

	}
	void PrintRecord()		//void PrintRecord(Student *const this)
	{
		cout<<"Roll No: "<<RollNo<<endl;
		cout<<"Name: "<<Name<<endl;
		cout<<"Age: "<<Age<<endl;
		cout<<"Salary: "<<Salary<<endl;
	}
	void CalculateSalary()
	{
		int Basic=12000;
		float HRA=3456.89;
		Salary=Basic+HRA;
	}
};
int main()
{
	Student s;
	s.AcceptRecord();		//s1.AcceptRecord(&s);
	s.PrintRecord();
	s.CalculateSalary();
	s.PrintRecord();
	return 0;
}

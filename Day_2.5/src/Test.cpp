#include <iostream>
using namespace std;
class Student
{
private:
	int RollNo;		//Data Member
	char Name[40];
public:
	int Age;
	float Salary;

	void AcceptRecord()		//void AcceptRecord(const Student *this)
	{
		cout<<"Enter RollNo: "<<endl;
		cin>>this->RollNo;
		cout<<"Enter Name: "<<endl;
		cin>>this->Name;
		cout<<"Enter Age: "<<endl;
		cin>>this->Age;

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
	void SetRollNo(int RollNo)	//Student *const this
	{
		this->RollNo=RollNo;
	}
};
int main()
{
	Student s;

	s.SetRollNo(100);		//s.SetRollNo(&s,RollNo);

	return 0;
}

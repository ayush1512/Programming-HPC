#include <iostream>
using namespace std;
class Student
{
public:
	int RollNo;		//Data Member
	char Name[40];
	int Age;

	void AcceptRecord()		//void AcceptRecord(const Student *this)
	{
		cout<<"Enter RollNo: "<<endl;
		cin>>RollNo;
		cout<<"Enter Name: "<<endl;
		cin>>Name;
		cout<<"Enter Age: "<<endl;
		cin>>Age;
	}
	void PrintRecord()
	{
		cout<<"Roll No: "<<RollNo<<endl;
		cout<<"Name: "<<Name<<endl;
		cout<<"Age: "<<Age<<endl;
	}
};
int main()
{
	Student s;
	s.AcceptRecord();
	s.PrintRecord();
	return 0;
}

#include <iostream>
using namespace std;
class Test
{
	int Num3;
public:
	int Num1;
	int Num2;
	void ShowData()
	{
		cout<<"Num1: "<<this->Num1<<" Num2: "<<this->Num2<<endl;
	}

	Test operator+(Test t)
	{
		Test tmp;
		tmp.Num1=this->Num1+t.Num1;
		tmp.Num2=this->Num2+t.Num2;
		return tmp;
	}
	bool operator>(Test t)
	{
		if(this->Num1>t.Num1 && this->Num2>t.Num2)
		{
			return true;
		}
		return false;
	}
	friend void Show();
};
void Show()
{
	Test t;
	t.Num3=300;
}
int main1()
{

	Test t1;
	Test t2;
	//t1.Num3=200;
	t1.Num1=100;
	t1.Num2=200;

	t2.Num1=50;
	t2.Num2=60;

	Test t3=t1+t2;		//Test t3=t1.operator+(&t1,t2)

	t3.ShowData();

	if(t1>t2)			//t1.ooperator>(&t1,t2)
	{
		cout<<"T1 is Greater"<<endl;
	}
	else
	{
		cout<<"T2 is Greater"<<endl;
	}
}

class Customer
{
public:
	int CustId;
	char Name[40];
	int NoOfUnit;
	float BillAmount;

	void GetData()
	{
		cout<<"Enter Cust Id: "<<endl;
		cin>>this->CustId;
		cout<<"Enter Name: "<<endl;
		cin>>this->Name;
		cout<<"Enter No of Unit: "<<endl;
		cin>>this->NoOfUnit;
	}

	void ShowData()
	{
		cout<<"Name: "<<this->Name<<" Bill Amount: "<<this->BillAmount<<endl;
	}

	void GenerateBill()
	{
		if(this->NoOfUnit<100)
		{
			this->BillAmount=this->NoOfUnit*5;
		}
		if(this->NoOfUnit>100 && this->NoOfUnit<201)
		{
			this->BillAmount=(100*5)+(this->NoOfUnit-100)*7;
		}
		if(this->NoOfUnit>200)
		{
			this->BillAmount=(100*5)+(100*7)+(this->NoOfUnit-200)*10;
		}
	}
};

int main()
{
	Customer c1;
	c1.GetData();		//c1.GetData(&c1)
	c1.ShowData();
	cout<<"After Bill Generate: "<<endl;
	c1.GenerateBill();
	c1.ShowData();
}





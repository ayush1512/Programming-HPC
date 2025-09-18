#include <iostream>
using namespace std;
class Account{
    private:
    int accNo;
    string name;
    int balance;

    public:
    Account();

    void setAccno(int a);
    void setName(string n);
    void setBalance(int b);

    int getAccno() const {return this->accNo;}
    string getName() const {return this->name;}
    int getBalance() const {return this->balance;}

    void AcceptRecord();
    void PrintRecord();
    virtual void calculateInterest() = 0;
};

Account::Account(){
    this->accNo = 1000;
    this->name = "Generic";
    this->balance = 0;
}

void Account::setAccno(int a){this->accNo=a;}
void Account::setName(string n){this->name=n;}
void Account::setBalance(int b){this->balance=b;}

void Account::AcceptRecord(){
    int a;
    cout << "Enter the Account Number: ";
    cin >> a;
    this->setAccno(a);
    
    string n;
    cout << "Enter the Account Holder Name: ";
    cin >> n;
    this->setName(n);
    
    int b;
    cout << "Enter the Account Balance: ";
    cin >> b;
    this->setBalance(b);
}

void Account::PrintRecord(){
    cout << "Account Number: " << getAccno() << endl;
    cout << "Account Holder Name: " << getName() << endl;
    cout << "Account Balance: " << getBalance() << endl;
}

class SavingsAccount : public Account{
    public:
    void calculateInterest(){
        int b;
        b = this->getBalance() + 0.15*(this->getBalance());
        this->setBalance(b);
    }
};

class CurrentAccount : public Account{
    public:
    void calculateInterest(){
        int b;
        b = this->getBalance() - 100;
        this->setBalance(b);
    }

};

int main(){
    Account* s1;
    Account* c1;
    s1 = new SavingsAccount();
    c1 = new CurrentAccount();

    cout << "Savings Account Detials:\n";
    cout << endl;
    s1->AcceptRecord();
    s1->calculateInterest();
    s1->PrintRecord();
    cout << endl;
    
    cout << "Current Account Detials:\n";
    cout << endl;
    c1->AcceptRecord();
    c1->calculateInterest();
    c1->PrintRecord();

    return 0;
}
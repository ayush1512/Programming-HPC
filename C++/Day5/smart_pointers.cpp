#include <iostream>
#include <memory>

using namespace std;

int main(){
    //Smart pointers in C++11
    //unique pointer
    unique_ptr<int> ptr1 = make_unique<int>(10);
    unique_ptr<int> ptr2 = move(ptr1); // transfer ownership
    cout << "Unique Pointer Value: " << *ptr2 << endl;
    // cout << "Unique Pointer Value: " << *ptr1 << endl;


    //shared pointer
    shared_ptr<int> sptr1 = make_shared<int>(20);
    shared_ptr<int> sptr2 = sptr1; // shared ownership
    cout << "Shared Pointer Value: " << *sptr1 << ", " << *sptr2 << endl;
    cout <<"sptr1 Address: " << sptr1.get() << ", sptr2 Address: " << sptr2.get() << endl;
    cout << "Shared Pointer Count: " << sptr1.use_count() << endl;

    //weak pointer
    weak_ptr<int> wptr = sptr1; // weak reference
    cout << "Weak Pointer Expired: " << wptr.use_count() << endl;
}
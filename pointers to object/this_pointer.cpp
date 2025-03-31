#include<iostream>
using namespace std;
class A{
    int a;
    public:
    void setData(int a ){
        this->a=a;
    }
    void getData(){
        cout<<"Value of a is: "<<a<<endl;

    }
};
int main()
{
    // this keyword is a pointer which points to the object which invokes the membrfunction 
    A a;
    a.setData(3);
    a.getData();
   return 0;
}
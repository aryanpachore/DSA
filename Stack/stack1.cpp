#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int main()
{

//creation of stack using stl 

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    cout<<s.top()<<endl;

    
    if(s.empty()){
        cout<<"Stack is empty";
    }else{
        cout<<"Stack is not empty";
    }

    cout<<endl;

    cout<<"size of srack: "<<s.size();



   return 0;
}
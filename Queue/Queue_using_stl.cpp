#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;

    q.push(12);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);


    cout<<"size of queue:"<<q.size()<<endl;

    cout<<"front element: "<<q.front()<<endl;

    q.pop();

     cout<<"size of queue:"<<q.size()<<endl;


    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<"queue is not empty"<<endl;
    }



   return 0;
}
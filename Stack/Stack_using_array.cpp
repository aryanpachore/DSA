#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;

stack(int size){
    this->size = size;
    arr = new int[size];
    top=-1;
}

void push(int element){
    if(size-top> 1){
         top++;
        arr[top] = element;
    }else{
        cout<<"Stack overflow"<<endl;
    }
}


void pop(){
    if(top>=0){
         top--;
    }else{
        cout<<"Stack underflow"<<endl;
        }
    }

int peak() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}


       

    


};



int main()
{

    stack s(5);

    s.push(3);
    s.push(4);

   cout<< s.peak()<< endl;


    s.pop();

    cout<<s.peak();

     return 0;
}
#include<iostream>
using namespace std;
int main()
{
    //pointer recap 
        int a =3;
        int* ptr = &a;
        cout << "Value of a: " << *(ptr) << endl;   //used derefrencing operator *() here.

    // new keyword/operator

        int* p = new int(40);// made a new int and stored 40 in it ; stored 40 at adreess p;can be of any datatype 
        cout << "Value at address p is : " << *p << endl;  //used derefrence operator

        int* arr = new int [3]; //dynamically alloctiong block of memory 
        arr[0] = 10;
        arr[1]= 20;
        arr[2]=30;
        cout << "Value at address arr[0] is : " << arr[0] <<endl;
        cout << "Value at address arr[1] is : " << arr[1] <<endl;
        cout << "Value at address arr[2] is : " << arr[2] <<endl;
     

    //delete keyword/operator
        delete[] arr; 
        cout << "Value at address arr[0] is : " << arr[0] <<endl;
        cout << "Value at address arr[1] is : " << arr[1] <<endl;
        cout << "Value at address arr[2] is : " << arr[2] <<endl;
   return 0;
}
#include<iostream>
using namespace std;

class complex{
 int real , img;
   public :
   void getData(){
      cout<<"The real part is "<<real<<endl;
      cout<<"The imaginary part is "<<img<<endl;
   }

   void setData(int a,int b){
      real=a;
      img=b;
   }
};
int main()
{

   // complex c1;
   // complex *ptr = &c1;
    complex* ptr = new complex;// dyamic allocation using new keyword/operator.
    (*ptr).setData(20,30);
//  (*ptr).getData(); is exactly same as 
    ptr->getData();

//Array of objects
   complex* ptr1 = new complex[3];
   for(int i=0;i<3;i++){
      ptr1[i].setData(i,i+1);
      }
   for(int i=0;i<3;i++){
         ptr1[i].getData();
      }
         delete ptr;
         delete[] ptr1;


   return 0;
}
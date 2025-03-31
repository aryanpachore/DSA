#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<string> s;
    s.insert("aryan"); //o(log n)
    s.insert("ankur");
    s.insert("mohit");
    for(auto val : s){
        cout<<val<<endl; //o(n)
    }
    s.find("ankur");


   return 0;
}
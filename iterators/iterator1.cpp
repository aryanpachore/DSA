#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v = {1,45,36,7,6,5,32,3,56,763,43,42,66};

    for(int val : v){ //copy of values present in this type of iteration
        val++;
        cout<<val<<" ";
    }
    cout<<endl;
    for(int &val : v){ // now this is reffering actual values of vector
        val++;
        cout<<val<<" ";
    }
    for(auto it = v.begin();it != v.end();++it){ //auto -> all data types
        cout<<(*it)++<<" ";
    }
   return 0;
}
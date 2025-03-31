#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    //creation
    unordered_map<string,int> m;

    //insertion-1
    m.insert({"apple",10});
    //insertion-2
    pair<string,int> p =make_pair("aryan",23);
    m.insert(p);
    // insertion-3
    pair<string,int> p2("love",34);
    m.insert(p2);
    //insertion-4
    m["hi"]=2;


    //search
    cout<<m["hi"]<<endl;
    cout<<m.at("aryan")<<endl;


    //size
    cout<<m.size()<<endl;

    //count 
    cout<<m.count("apple")<<endl;

    //erase
    m.erase("love"); 
    
    for(auto i: m){
        cout<<i.first<<"->"<<i.second<<endl;

    }
cout<<endl;


    //iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
            cout<<it->first<<"->"<<it->second<<endl;
            it++;
    }


   return 0;
}
#include<iostream>
#include<map>
using namespace std;
int main()
{
map<int,string> m;
m.insert({1,"aryan"});
m.insert({2,"abhinav"});
m.insert({5,"ankur"});
m[3] = "Mohit";

for(auto it: m){
    cout<<it.first<<":"<<it.second<<endl;
}
auto it = m.find(7);
if(it == m.end()){
    cout<<" is not present in map"<<endl;

}else{
    cout<<(*it).first<<" "<<(*it).second;
}
   return 0;
}


// unordered map doesnot store data in ordered way as 
//it uses hashing in implementation therefore its T.C is less as compared to maps
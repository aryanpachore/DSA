#include<iostream>
#include<unordered_map>
#include <list>
using namespace std;


class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addedge(int u,int v,int w){
    pair<int,int> p = make_pair(v,w);

    adj[u].push_back(p);
    }

    void topological(unordered_map<int,list<pair<int,int>>> &adj , vector<int> &vis, )
    
}
int main()
{
   return 0;
}
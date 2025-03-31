#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

struct cityRecord{
  string cityname;
  uint64_t population;
  double latitude , longitude;
};
int main()
{

   unordered_map<string, cityRecord> citymap;
   citymap["newYork"] = cityRecord {"newYork", 30000000,2.3,2.5};
   citymap["delhi"] = cityRecord {"delhi", 300000,2.9,2.8};
   citymap["mumbai"] = cityRecord {"mumbai", 3000000,2.2,2.1};
   citymap["bhopal"] = cityRecord {"bhopal", 300,2.6,2.7};

cityRecord& newYorkData = citymap["newYork"];
newYorkData.population;// can print if we want 


   return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


vector<int> solve (int N, int K, int Q, vector<int> A, vector<int> Queries) {
    // Write your code here
     set<int> buildings;
     multiset<int>greenSpace;
     buildings.insert(0);
     buildings.insert(K);
     greenSpace.insert(K);
     vector<int> maxSegment(N);
     for(int i = 0;i<N;++i){
         int position = A[i]; 
         auto rightBound = buildings.lower_bound(position);
         auto leftBound = prev(rightBound);
         int curr = *rightBound - *leftBound;
         greenSpace.erase(greenSpace.find(curr));
         int leftSegment = position- *leftBound;
         int rightSegment = *rightBound - position;
         greenSpace.insert(leftSegment);
         greenSpace.insert(rightSegment);
         buildings.insert(position);
         maxSegment[i] = *greenSpace.rbegin();
     }
     vector<int> result;
     for(int q: Queries){
         result.push_back(maxSegment[q-1]);
             }
             return result;
            }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> Queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> Queries[i];
    }

    solve(N, K, Q, A, Queries);

    return 0;
}

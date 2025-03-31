#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> parent, power;
vector<vector<pair<int, int>>> adj;

void dfs(int node, int par, int p) {
    parent[node] = par;
    power[node] = p;
    for (auto &edge : adj[node]) {
        int next = edge.first;
        int w = edge.second;
        if (next != par) {
            dfs(next, node, w);
        }
    }
}

int findHighestNode(int u, long long H) {
    while (u != -1) {
        if (H < power[u]) {
            break;
        } else if (H == power[u]) {
            u = parent[u];
            break;
        } else {
            H -= power[u];
            u = parent[u];
        }
    }
    return (u == -1) ? 1 : u;
}

vector<int> solve(int n, vector<vector<int>> edges, int q, vector<vector<long long>> queries) {
    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    power.resize(n + 1, 0);

    for (auto &e : edges) {
        int u = e[0], v = e[1], p = e[2];
        adj[u].emplace_back(v, p);
        adj[v].emplace_back(u, p);
    }

    dfs(1, -1, 0);

    vector<int> result;
    for (auto &query : queries) {
        int u = query[0];
        long long H = query[1];
        result.push_back(findHighestNode(u, H));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(3));

    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cin >> q;
    vector<vector<long long>> queries(q, vector<long long>(2));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> res = solve(n, edges, q, queries);

    for (int ans : res) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}

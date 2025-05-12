#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007
// Disjoint Set Union 
class DisjointSet {

    // DSU by size
    vector<int>parent, size;
    public:
    DisjointSet(int n) {

        parent.resize(n + 1);

        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // finds ultimate parent and des path compression
    int findParent(int node) {  
        if (node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }
    
    // union by size
    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        // belong to same component
        if (ulp_u == ulp_v) return;

        // attach smaller one to bigger
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/GRAPHS/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/GRAPHS/output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    DisjointSet s(n);

    s.unionBySize(2, 3);

    for(int i=1;i<=n;i++) {

        cout << s.findParent(i) << endl;
    }
    return 0;
}
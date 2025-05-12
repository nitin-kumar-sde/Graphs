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
// vector<int> Adj[N];

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

int p[N];
int q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/GRAPHS/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/GRAPHS/output.txt", "w", stdout);
    #endif

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        int m; cin >> m;

        for(int i=1;i<=n;i++)
        cin >> p[i];

        for(int i=1;i<=n;i++)
        cin >> q[i];

        DisjointSet ds(n);

        for(int i=0;i<m;i++) {
            int u, v;
            cin >> u >> v;
            ds.unionBySize(p[u],p[v]);
        }

        bool isPossible = true;

        for(int i=1;i<=n;i++) {
            if(p[i] == q[i])
            continue;

            if(ds.findParent(p[i]) != ds.findParent(q[i]))
            {
                isPossible = false;
                break;
            }
        }

        if(isPossible) 
        cout << "YES" << endl;
        else
        cout << "NO" << endl;

       
    }

    return 0;
}
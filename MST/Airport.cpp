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

// Edge class represents edge between 2 nodes
class Edge {
    public:
    int source;
    int dest;
    int weight;
};

// sorting edges based on edge weight
bool compare(const Edge &a, const Edge &b) {
    return a.weight < b.weight;  
}

pair<int, int> kruskals(Edge* edges, int e, int n, int a) {

    sort(edges, edges + e, compare);

    DisjointSet ds(n);

    // Edge * output = new Edge[n-1];
    int count = 0;
    int i=0;

    int sum = 0;
    while(count < n-1 && i < e) {
        // check if adding edge forms a cycle or not
        if(ds.findParent(edges[i].source) != ds.findParent(edges[i].dest)) {
            if(edges[i].weight > a)
            break;
            sum += edges[i].weight;
            ds.unionBySize(edges[i].source, edges[i].dest);
            count++;
            // cout << sum << " debug " << count << endl;
            // cout << edges[i].source << " edges " << edges[i].dest << endl;

        }
        i++;
    }
    int numComp = n - count;
    sum += (numComp * a);
    // cout << "num " << numComp << endl;
    return {sum, numComp};

 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/GRAPHS/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/GRAPHS/output.txt", "w", stdout);
    #endif

    int T; cin >> T;

    for(int t = 1; t<=T; t++) {

        int n,m,a;
        cin >> n >> m >> a;

        Edge * edges = new Edge[m];

        for(int i=0;i<m;i++) {
            int u, v, w;
            cin >> u >> v >> w;
            // build edge
            edges[i].source = u;
            edges[i].dest = v;
            edges[i].weight = w;
        }

        pair<int, int> minCost = kruskals(edges, m, n, a);

        cout << "Case #" << t << ":" << minCost.first << " " << minCost.second << endl;


    }

    return 0;
}
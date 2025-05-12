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


void kruskals(Edge* edges, int e, int n) {

    sort(edges, edges + e, compare);

    DisjointSet ds(n);

    Edge * output = new Edge[n-1];
    int count = 0;
    int i=0;

    while(count < n-1) {
        // check if adding edge forms a cycle or not
        if(ds.findParent(edges[i].source) != ds.findParent(edges[i].dest)) {
            output[count] = edges[i];
            ds.unionBySize(edges[i].source, edges[i].dest);
            count++;
        }
        i++;
    }

    for(int i=0;i<n-1;i++) {
        cout << min(output[i].source, output[i].dest) << " " << max(output[i].source, output[i].dest)
        << " " << output[i].weight << endl;
    }

 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/GRAPHS/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/GRAPHS/output.txt", "w", stdout);
    #endif

   int n,e;
   cin >> n >> e;

   Edge * edges = new Edge[e];

   for(int i=0;i<e;i++) {

       int u, v, w;
       cin >> u >> v >> w;
       edges[i].source = u;
       edges[i].dest = v;
       edges[i].weight = w;
   }

   kruskals(edges, e, n);

   return 0;
}

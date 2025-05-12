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
vector<int> Adj[N];
int visited[N] = {0};
// dfs tp traverse graph for cllecting topo-sort
void dfs(int src, stack<int> & s) {
    // entry to src
    visited[src] = 1;

    for(int it : Adj[src]) {
        // cycle detection - toposort not possible
        if(visited[it] == 1)
        return ;

        if(visited[it] == 0)
        dfs(it, s);
    }

    visited[src] = 2;
    s.push(src);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/GRAPHS/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/GRAPHS/output.txt", "w", stdout);
    #endif

    int n,m; cin >> n >> m;
    
    // only applicable for DAGs(Directed Acyclic Graphs)
    for(int i=0;i<m;i++) {
        int u,v; 
        cin >> u >> v;
        Adj[u].push_back(v);
    }

    stack<int> s;

    for(int i=1;i<=n;i++) {
        if(visited[i] == 0)
        dfs(i, s);
    }

    vector<int> toposorting;

    while(!s.empty()) {
     int top = s.top();
     s.pop();
     toposorting.push_back(top);
    }

    for(int it : toposorting) {
        cout << it << " ";
    }

    return 0;
}
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
int tin[N] = {0};
int tout[N] = {0};
int color[N] = {0};
int timer = 0;
void dfs(int src) {
    
    // 1 - represents Grey - partially explored, not fully
    color[src] = 1; 
    // captures entry time of every node.
    tin[src] = timer++;

    // explore src - custom logic
    cout << src << " ";

    for(auto it : Adj[src]) {
        
        if(color[it] != 0) continue;
        
        dfs(it);
    }
    // captures exit time of every node.
    tout[src] = timer++;

    // 2 -represents black - fully explored 
    color[src] = 2;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/GRAPHS/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/GRAPHS/output.txt", "w", stdout);
    #endif
    
    int n, m; 
    cin >> n >> m;
    

    for(int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    
    for(int i=0;i<n;i++) {
        if(color[i] == 0)
        dfs(i);
    }
    

    return 0;
}
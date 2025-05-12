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
int low[N] = {0};
int visited[N] = {0};
int timer = 0;
// collects bridges - edges whoses removal, breaks graph

void tarjan(int src, int parent, vector<pair<int, int>> & bridges) {

    visited[src] = 1; 

    tin[src] = low[src] = timer++;

    for(auto it : Adj[src]) {
        
        if(it == parent) 
        continue;

        if(visited[it] == 0)
        {
            tarjan(it, src, bridges);

            low[src] = min(low[src], low[it]);

            // check and add if its a bridge
            if(low[it] > tin[src])
            bridges.push_back({src, it});

        }
        else
        low[src] = min(low[src], tin[it]);
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

    int n, m; 
    cin >> n >> m;

    for(int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    
    vector<pair<int, int>> bridges;

    for(int i=0;i<n;i++) {
        if(visited[i] == 0)
        tarjan(i, -1, bridges);
    }

    for(auto it : bridges) {
        
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}
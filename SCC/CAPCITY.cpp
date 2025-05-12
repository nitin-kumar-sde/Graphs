#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
vector<int> AdjT[N];
int visited[N];

// gets the vertices based on finishing time
void dfs(int src, stack<int> &s) {
    
    visited[src] = 1; 

    for(auto it : Adj[src]) {
        
        if(visited[it] == 1) continue;
        
        dfs(it, s);
    }
    s.push(src);
}

// dfs on transpose matrix to collect SCC
void kosaraju(int src, int comp_num) {
    
    visited[src] = comp_num; 
    // cout << src << " ";
    for(auto it : AdjT[src]) {
        
        if(visited[it] != 0) continue;
        
        kosaraju(it, comp_num);
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
        AdjT[v].push_back(u);
    }

    stack<int> s;
    for(int i=1;i<=n;i++) {
        if(visited[i] == 0)
        dfs(i,s);
    }

    for(int i=1;i<=n;i++)
    visited[i] = 0;

    int scc_num = 1;

    while(!s.empty()) {

        int top = s.top();
        s.pop();
        if(visited[top] == 0)
        {
            kosaraju(top, scc_num);
            scc_num++;
        }
    }
    // cout << scc_num << endl;

    int * st = new int[scc_num];
    fill(st, st + scc_num, 0);

    for(int i=1;i<=n;i++) {
        vector<int> adj = Adj[i];
        for(int node : adj) {
            if(visited[i] != visited[node])
            st[visited[i]]++;
        }
    }

    vector<int> reachableNodes;

    for(int i=1;i<=n;i++) {
        if(st[visited[i]] == 0)
        reachableNodes.push_back(i);
    }

    int count = 0;

    for(int i=1;i<scc_num;i++) {
        count += (st[i] == 0);
    }

    if(count > 1)
    reachableNodes.clear();
    
    cout << reachableNodes.size() << endl;

    for(int node : reachableNodes)
    cout << node << " ";

    return 0;
}
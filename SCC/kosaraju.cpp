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
void kosaraju(int src) {
    
    visited[src] = 1; 
    cout << src << " ";
    for(auto it : AdjT[src]) {
        
        if(visited[it] == 1) continue;
        
        kosaraju(it);
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
    for(int i=0;i<n;i++) {
        if(visited[i] == 0)
        dfs(i,s);
    }

    for(int i=0;i<n;i++)
    visited[i] = 0;
    int scc = 0;

    while(!s.empty()) {

        int top = s.top();
        s.pop();
        if(visited[top] == 0)
        {
            kosaraju(top);
            scc++;
            cout << endl;
        }
    }
    
    

    return 0;
}
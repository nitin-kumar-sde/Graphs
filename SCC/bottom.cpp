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

    while(true) {
        int n; cin >> n;
        if(n==0) break;

        int m; cin >> m;

        for(int i=1;i<=n;i++) {
            Adj[i].clear();
            AdjT[i].clear();
            visited[i] = 0;
        }

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

        for(int node : reachableNodes)
        cout << node << " ";

        cout << endl;

    }

    return 0;
}
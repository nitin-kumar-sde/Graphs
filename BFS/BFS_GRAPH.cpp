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
vector<int> Adj[N+1];

// time complexity - O(V + E)
// space complexity - O(2*V) = O(V)
void bfs(int source, vector<int> Adj[], int n, int visited []) {
    
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " ";

        for(int it : Adj[top]) {

            if(!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n >> m;

    for(int i=0;i<m;i++) {
        int u,v; 
        cin >> u >> v;

        // for undirected graphs
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int visited [N+1] = {0};

    for(int i=0;i<n;i++) {
        if(!visited[i])
        bfs(i, Adj, n, visited);
    }
    
    return 0;
}
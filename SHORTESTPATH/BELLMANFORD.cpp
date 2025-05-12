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

int dist [N] = {0};
vector<pair<int,int> >Adj[N];

void initialise(int n) {
    for(int i=1;i<=n;i++) 
    dist[i] = 1e9;
}

// time complexity - O(V*E)
void bellmanFord(int src, int n) {

    dist[src] = 0;

    for(int i=0;i<n-1;i++) {
        // relax all the edges 
        for(int i=1;i<=n;i++) {
            for(auto it : Adj[i]) {
                if(dist[it.first] > dist[i] + it.second)
                dist[it.first]  = dist[i] + it.second;
            }
        }
    }
    // check if any edge can be relaxed - after n-1 times
    for(int i=1;i<=n;i++) {
        for(auto it : Adj[i]) {
            if(dist[it.first] > dist[i] + it.second)
            cout << "Graph contains cycle with total negative weights";
            return;
        }
    }
    for(int i=1;i<=n;i++) {
        cout << dist[i] << endl;
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

    int n,m; 
    cin >> n >> m;

    // initialise the distances to all nodes to INF
    initialise(n);


    // take graph input 
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].push_back({v, w});
        Adj[v].push_back({u, w});
    }

    // fials in case of negative weight cycle, but can detect it.
    bellmanFord(1, n);
    
    return 0;
}
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

vector<pair<int,int> >Adj[N];

int visited [N] = {0};
int dist [N] = {0};

void initialise(int n) {

    for(int i=1;i<=n;i++) 
    dist[i] = 1e9;

}

// time complexity - O((V+E)* logV)
void dijkstra(int src, int n) {

    dist[src]  = 0;
    set<pair<int,int> > s;

    s.insert({0, src});

    while(!s.empty()) {
        auto it = *s.begin();
        s.erase(s.begin());

        int dis = it.first;
        int node = it.second;

        if(visited[node]) continue;

        visited[node] = 1;

        for(auto it : Adj[node]) {
            if( dist[it.first] > it.second + dist[node] ) {
                dist[it.first] = it.second + dist[node];
                s.insert({dist[it.first], it.first});
            } 
        }

    }

    for(int i=1;i<=n;i++) {
        cout << "Distance of " << i << " is " << dist[i] << endl; 
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

    // fails if graph contains negative 
    dijkstra(1, n);
    
    return 0;
}
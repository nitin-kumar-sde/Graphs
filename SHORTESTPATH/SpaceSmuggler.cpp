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
vector<pair<int,int> >AdjT[N];

int dis_src[N];
int dis_dest[N];

int dis_T_src[N];
int dis_T_dest[N];

int visited [N] = {0};

void dijkstra(int src, int n, int dis[], vector<pair<int,int> > Adj[]) {

    for(int i=1;i<=n;i++) {
        dis[i] = 1e9;
        visited[i] = 0;
    }

    dis[src]  = 0;
    set<pair<int,int> > s;

    s.insert({0, src});

    while(!s.empty()) {
        auto it = *s.begin();
        s.erase(s.begin());

        // int dis = it.first;
        int node = it.second;

        if(visited[node]) continue;

        visited[node] = 1;

        for(auto it : Adj[node]) {
            if( dis[it.first] > it.second + dis[node] ) {
                dis[it.first] = it.second + dis[node];
                s.insert({dis[it.first], it.first});
            } 
        }

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



    int n; cin >> n; 
    int m; cin >> m;

    int src, dest;
    cin >> src >> dest;

    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin  >> u >> v >> w;
        // building graph
        Adj[u].push_back({v, w});
        // building Transpose graph
        AdjT[v].push_back({u, w});
    }

    dijkstra(src, n, dis_src, Adj);
    dijkstra(dest, n, dis_dest, Adj);
    dijkstra(src, n, dis_T_src, AdjT);
    dijkstra(dest, n, dis_T_dest, AdjT);

    int ans = INT_MAX;

    for(int i=1;i<=n;i++) {
        if(i == src || i == dest)
        continue;

        ans = min(ans, dis_src[i] + dis_T_dest[i] + dis_dest[i] + dis_T_src[i]);
    }

    cout << ans << endl;

    return 0;
}
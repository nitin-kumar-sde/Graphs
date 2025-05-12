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
vector<pair<int,int> > Adj[N];
int col[N];
bool isBipartite = true;

void dfs(int src, int color) {

    col[src] = color;

    for(auto it : Adj[src]) {
        int nextColor = color ^ it.second;

        if(col[it.first] == -1) {
            dfs(it.first, nextColor);
        }
        if(col[it.first] != nextColor) {
            isBipartite = false;
            return ;
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

    int t; cin >> t;

    while(t--) {
        int n,q;
        cin >> n >> q;

        for(int i=1;i<=n;i++) {
            Adj[i].clear();
            col[i] = -1;
        }
        isBipartite = true;

        for(int i=1;i<=q;i++) {
            int u,v,w;
            cin >> u >> v >> w;
            Adj[u].push_back({v, w});
            Adj[v].push_back({u, w});
        }

        for(int i=1;i<=n;i++) {
            if(col[i] == -1) {
                dfs(i, 0);

                if(!isBipartite) {
                    break;
                }
            }
        }

        if(isBipartite)
        cout << "yes" << endl;
        else
        cout << "no" << endl;
        
    }

    return 0;
}
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
#define N 10005
#define MOD 1000000007
int dist [N][N] = {0};

void initialise(int n) {

    for(int i=1;i<=n;i++) {
       for(int j=1;j<=n;j++) {
           if(i==j)
           dist[i][j] = 0;
           else
           dist[i][j] = 1e9;
        }
    }
}

// time complexity - O(v^3)
// dp based solution 
void floydWarshal(int n) {

    for(int k=1;k<=n;k++) {

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }

    }
    // check for negative weight cycles
    for(int i=1;i<=n;i++) {
        if(dist[i][i] < 0) {
            cout << "Cycle with negative weight found" << endl;
            return;
        }
    }
    // distances between all the pairs
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) 
        cout << dist[i][j] << " ";
        cout << endl;
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
    initialise(n);
    
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
    }

    floydWarshal(n);
    return 0;
}
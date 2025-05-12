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
#define N 1005
#define MOD 1000000007
int MAT[N+1][N+1];
int drow[] = {-1, 1, 0, 0};  
int dcol[] = {0, 0, -1, 1}; 

void bfs(int n, int m) {

     queue<pair<int, int>> q;
     int minDistance[N+1][N+1];

     for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(MAT[i][j] == 0) { 
            minDistance[i][j] = 0;
            q.push({i,j});
            }
            else 
            minDistance[i][j] = 1e9;
        }
     }

     while(!q.empty()) {

        pair<int,int> front = q.front(); q.pop();

        for(int i=0;i<4;i++) {
            int new_x = front.first + drow[i];
            int new_y = front.second + dcol[i];

            if(new_x >=0 && new_x < n && new_y >=0 && new_y < m 
            && minDistance[new_x][new_y] == 1e9)
            {minDistance[new_x][new_y] = 1 + 
            minDistance[front.first][front.second];

            q.push({new_x, new_y});
            }
        }

    }

    for(int i=0;i<n;i++) {

        for(int j=0;j<m;j++)
        cout << minDistance[i][j] << " ";
        cout << endl;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; 
    cin >> n >> m;

    for(int i=0;i<n;i++) {
       for(int j=0;j<m;j++) {
         cin >> MAT[i][j];
       }
    }

    bfs(n,m);

    return 0;
}
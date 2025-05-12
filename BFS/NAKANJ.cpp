#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 8
#define MOD 1000000007
int chess[N+1][N+1];
int drow[] = {1, 1, 2, 2, -1, -1, -2, -2};  
int dcol[] = {2, -2, -1, 1, -2, 2, 1, -1}; 

int bfs(int start_x, int start_y, int end_x, int end_y) {
    
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++)
        chess[i][j] = 1e9;
    }
    chess[start_x][start_y] = 0;

    if(start_x == end_x && start_y == end_y)
    return 0;
    
    queue<pair<int, int>> q;
    q.push({start_x, start_y});

    while(!q.empty()) {
        pair<int,int> front = q.front(); 
        q.pop();

        for(int i=0;i<8;i++) {
            int new_x = front.first + drow[i];
            int new_y = front.second + dcol[i];

            if(new_x == end_x && new_y == end_y)
            return 1 + chess[front.first][front.second];

            if(new_x >=0 && new_x <= 7 && new_y >=0 && new_y <= 7 
            && chess[new_x][new_y] == 1e9){
            chess[new_x][new_y] = 1 + 
            chess[front.first][front.second];

           

            q.push({new_x, new_y});
            }
        }

    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int k; cin >> k;

    while(k--) {
        string s,t; cin >> s >> t;
        int start_x = s[0] - 'a';
        int start_y = s[1] - '1';
        int end_x = t[0] - 'a';
        int end_y = t[1] - '1';

        int ans = bfs(start_x, start_y, end_x, end_y);
        cout << ans << endl;
    }

    return 0;
}
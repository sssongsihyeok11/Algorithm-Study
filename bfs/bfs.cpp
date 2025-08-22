#include <iostream>
#include <vector>
#include <queue>
#define r first
#define c second
using namespace std;

int board[502][502] = {0};
bool visited[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while(!q.empty()){
        pair<int ,int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.r + dx[i];
            int ny = cur.c + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        } 
    }
}
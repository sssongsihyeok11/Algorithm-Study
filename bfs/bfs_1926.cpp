#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define r first
#define c second
#define MAXN 501
#define MAXM 501
using namespace std;

int board[MAXN][MAXM];
int n, m;
bool visited[MAXN][MAXM];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};


int bfs(int st_r, int st_c){
    queue<pair<int, int>> q;
    q.push({st_r, st_c});
    visited[st_r][st_c] = true;
    int cnt = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if(nr < 1 || nr > n || nc < 1 || nc > m) continue;
            if(visited[nr][nc] || board[nr][nc] == 0) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
            cnt++;
        }
    }

    return cnt;
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
            visited[i][j] =false;
        }
    }
}

void solution(){
    int ms = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 1 && ! visited[i][j]){
                int sz = bfs(i, j);
                ms = max(ms, sz);
                cnt++;
            }
        }
    }

    cout << cnt <<"\n" << ms;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();

    return 0;
}

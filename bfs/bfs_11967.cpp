#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 101
#define r first
#define c second

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int>> light[MAXN][MAXN];
queue<pair<int, int>> q;
bool visited[MAXN][MAXN];
bool canGo[MAXN][MAXN];
int n, m;

void bfs(){
    q.push({1, 1});
    visited[1][1] = true;
    canGo[1][1] = true;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < light[cur.r][cur.c].size(); i++){
            int nr = light[cur.r][cur.c][i].r;
            int nc = light[cur.r][cur.c][i].c;

            canGo[nr][nc] = true;
        }

        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(nr < 1 || nr > n || nc < 1 || nc > n) continue;
            if(visited[nr][nc] || !canGo[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

bool check(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(canGo[i][j] && !visited[i][j]){
                if(i - 1 >= 1 && visited[i - 1][j]) return false;
                if(i + 1 <= n && visited[i + 1][j]) return false;
                if(j - 1 >= 1 && visited[i][j - 1]) return false;
                if(j + 1 <= n && visited[i][j + 1]) return false; 
            }
        }
    }
    return true;
}
void init(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        light[x][y].push_back({a, b});
    }

    memset(visited, false, sizeof(visited));
    memset(canGo, false, sizeof(canGo));
}

void solution(){
    while(1){
        bfs();
        if(check()) break;
        else memset(visited, false, sizeof(visited));
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(canGo[i][j] && visited[i][j]) cnt++;
        }
    }

    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}
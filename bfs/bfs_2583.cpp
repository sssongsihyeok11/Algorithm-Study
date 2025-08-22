#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define r first
#define c second
#define MAXN 101
#define MAXM 101

using namespace std;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
bool visited[MAXN][MAXM];
bool cango[MAXN][MAXM];
int m, n, k; //m : col, n : row, k : #of vectors
priority_queue<int, vector<int>, greater<int>> pq;

int bfs(int row, int col){
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(visited[nr][nc] || !cango[nr][nc]) continue;

            visited[nr][nc] = true;
            cnt++;
            q.push({nr, nc});
        }
    }

    return cnt;
}
void init(){
    cin >> m >> n >> k;
    memset(visited, false, sizeof(visited));
    memset(cango, true, sizeof(cango));
    for(int i = 0; i < k; i++){
        int r0, c0, r1, c1;
        cin >> r0 >> c0 >> r1 >> c1;

        for(int i = r0; i < r1; i++){
            for(int j = c0; j < c1; j++){
                cango[i][j] = false;
            }
        }
    }
} 

void solution(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && cango[i][j]){
                pq.push(bfs(i, j));
            }
        }
    }

    cout << pq.size() <<"\n";

    while(!pq.empty()){
        cout << pq.top() <<" ";
        pq.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}
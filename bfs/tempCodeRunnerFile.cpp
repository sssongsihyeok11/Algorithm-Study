#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define r first
#define c second
#define MAXR 1001
#define MAXC 1001
#define INF 100000000
using namespace std;

int row, col;
char map[MAXR][MAXC];
bool visited[MAXR][MAXC];
int fire_step[MAXR][MAXC];
int dr[4] = {1, 0, -1 ,0};
int dc[4] = {0, 1, 0, -1};
pair<int, int> fire;
pair<int, int> jihun;

void set_fire_step(){
    // 모든 위치를 INF로 초기화
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            fire_step[i][j] = INF;
        }
    }
    
    queue<pair<int, int>> q;
    q.push({fire.r, fire.c});
    fire_step[fire.r][fire.c] = 0;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(nr < 1 || nr > row || nc < 1 || nc > col) continue;
            if(map[nr][nc] =='#') continue;
            if(fire_step[nr][nc] != INF) continue;

            fire_step[nr][nc] = fire_step[cur.r][cur.c] + 1;
            q.push({nr, nc});
        }
    }
}

bool escape(int cr, int cc){
    return(cr == row || cr == 1 || cc == 1 || cc == col);
}

void can_escape(){
    if(escape(jihun.r, jihun.c)){
        cout << 1;
        return;
    }
    
    queue<pair<int, int>> q;
    q.push({jihun.r, jihun.c});
    visited[jihun.r][jihun.c] = true;

    int time = 0;
    
    while(!q.empty()){
        int qsize = q.size();
        time++;
        
        for(int t = 0; t < qsize; t++){
            pair<int, int> cur = q.front(); q.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];

                if(nr < 1 || nr > row || nc < 1 || nc > col) continue;
                if(map[nr][nc] == '#') continue;
                if(visited[nr][nc]) continue;
                if(fire_step[nr][nc] <= time) continue; 

                visited[nr][nc] = true;
                
                if(escape(nr, nc)) {
                    cout << time;
                    return;
                }
                
                q.push({nr, nc});
            }
        }
    }

    cout << "IMPOSSIBLE";
}

void init(){
    cin >> row >> col;

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            visited[i][j] = false;
            cin >> map[i][j];
            
            if(map[i][j] =='F'){
                fire.r = i;
                fire.c = j;
            }
            else if(map[i][j] == 'J'){
                jihun.r = i;
                jihun.c = j;
            }
        }
    }
}

void solution(){
    set_fire_step();
    can_escape();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
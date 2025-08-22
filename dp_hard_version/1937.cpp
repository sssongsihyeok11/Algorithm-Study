#include <iostream>
#include <algorithm>
#define MAXN 501

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int map[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;


int backtracking(int r, int c){
    
    int &ret = dp[r][c];
    if(ret != -1) return ret;

    ret = 0;
    bool flag= false;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 1 || nr > n || nc < 1 || nc > n) continue;
        if(map[r][c] >= map[nr][nc]) continue;

        flag = true;
        ret = max(ret, backtracking(nr, nc) + 1);
    }

    if(!flag) return ret = 1;
    return ret;
}

void init(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
}

void solution(){
    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans = max(ans, backtracking(i, j));
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
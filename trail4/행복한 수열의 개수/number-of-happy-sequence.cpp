#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

bool isHappyArray_col(int c){
    int v = grid[0][c];
    int max_cnt = -1;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(v == grid[i][c]) cnt++;
        else{
            v = grid[i][c];
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
    }
    max_cnt = max(max_cnt, cnt);
    return max_cnt >= m;
}

bool isHappyArray_row(int r){
    int v = grid[r][0];
    int cnt = 1;
    int max_cnt = -1;

    for(int i = 1; i < n; i++){
        if(v == grid[r][i]) cnt++;
        else{
            v = grid[r][i];
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
    }
    max_cnt = max(max_cnt, cnt);
    return max_cnt >= m;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        if(isHappyArray_col(i)) res ++;
        if(isHappyArray_row(i)) res ++;
    }
    cout << res;
    return 0;
}

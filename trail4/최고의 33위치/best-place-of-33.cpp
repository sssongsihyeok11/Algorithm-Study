#include <iostream>

using namespace std;

int N;
int grid[20][20];

int getCoin(int r, int c){
    int cnt = 0;
    for(int i = r; i < r + 3; i++){
        for(int j = c; j < c + 3; j++){
            if(grid[i][j] == 1) cnt++;
        }
    }

    return cnt;
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int res = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i + 3 <= N && j + 3 <= N){
                res = max(res, getCoin(i, j));
            }
        }
    }

    cout << res;
    // Please write your code here.

    return 0;
}

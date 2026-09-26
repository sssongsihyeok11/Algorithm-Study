#include <iostream>

using namespace std;

int n;
int grid[50][50];
int copy_grid[50][50];
void debug(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] <<" ";
        }
        cout <<"\n";
    }
}

void bomb(int r, int c){
    int val = grid[r][c];
    //up
    for(int i = r; i >= max(0, r - (val - 1)); i--){
        grid[i][c] = 0;
    }
    //down
    for(int i = r; i <= min(n - 1, r + (val - 1)); i++){
        grid[i][c] = 0;
    }
    //left
    for(int i = c; i >= max(0, c - (val - 1)); i--){
        grid[r][i] = 0;
    }
    //right
    for(int i = c; i <= min(n - 1, c + (val - 1)); i++){
        grid[r][i] = 0;
    }
}

void moveDown(){
    for(int c = 0; c < n; c++){
        int tmp[100];
        int tmp_idx = 0;

        for(int i = 0; i < n; i++){
            if(grid[i][c] != 0){
                tmp[tmp_idx++] = grid[i][c];
                grid[i][c] = 0;
            }
        }

        for(int i = tmp_idx - 1; i >= 0; i--){
            grid[n - 1 - (tmp_idx - 1 - i)][c] = tmp[i];
        }
    }
}

void copy(bool start){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(start){
                copy_grid[i][j] = grid[i][j];
            }
            else grid[i][j] = copy_grid[i][j];
        }
    }
}

int setCount(){
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != 0){

                if(i + 1 < n && grid[i][j] == grid[i + 1][j]) cnt++;
                if(j + 1 < n && grid[i][j] == grid[i][j + 1]) cnt++;
            }
        }
    }

    return cnt;
}
int main() {
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    copy(true);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bomb(i, j);
            moveDown();

            res = max(res, setCount());
            copy(false);
        }
    }

    cout << res;
    return 0;
}

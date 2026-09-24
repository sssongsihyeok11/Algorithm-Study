#include <iostream>

using namespace std;

int N, M, K;
int grid[100][100];

bool canBomb(int c){
   int cnt = 0;
    int prev;
    int prev_idx;
    for(int i = 0; i < N; i++){
        if(grid[i][c] != 0){
            cnt = 1;
            prev = grid[i][c];
            prev_idx = i;
            break;
        }
    }

    if(cnt == 0) return false;
    for(int i = prev_idx + 1; i < N; i++){
        if(prev == grid[i][c]){
            cnt++;
        }
        else{
            if(cnt >= M) return true;
            cnt = 1;
            prev = grid[i][c];
            prev_idx = i;
        }
    }

    return cnt >= M;
}
void searchAndBomb(int c){
    int cnt = 0;
    int prev;
    int prev_idx;
    for(int i = 0; i < N; i++){
        if(grid[i][c] != 0){
            cnt = 1;
            prev = grid[i][c];
            prev_idx = i;
            break;
        }
    }

    for(int i = prev_idx + 1; i < N; i++){
        if(prev == grid[i][c]){
            cnt++;
        }
        else{
            if(cnt >= M){
                for(int j = prev_idx; j < i; j++) grid[j][c] = 0;
            }
            cnt = 1;
            prev = grid[i][c];
            prev_idx = i;
        }
    }

    if(cnt >= M){
        for(int i = N - 1; i > N - 1 - cnt; i--) grid[i][c] = 0;
    }
}

void moveDown(int c){
    int arr[100];
    int arr_idx = 0;

    for(int i = 0; i < N; i++){
        if(grid[i][c] != 0){
            arr[arr_idx] = grid[i][c];
            arr_idx += 1;
            grid[i][c] = 0;
        }
    }

    for(int i = arr_idx - 1; i >= 0; i--){
        grid[N - (arr_idx - i)][c] = arr[i];
    }
}

void rotate_2d(){
    int copy[100][100];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            copy[j][N - 1 - i] = grid[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grid[i][j] = copy[i][j];
        }
    }
}
void debug(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << grid[i][j] <<" ";
        }
        cout <<"\n";
    }

    cout <<"\n\n";
}


int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < K; i++){

        for(int c = 0; c < N; c++){
            while(canBomb(c)){
                searchAndBomb(c);
                moveDown(c);
            }
        }
        rotate_2d();
        for(int c = 0; c < N; c++){
            moveDown(c);
        }
    }

    while(1){
        bool allNotBomb = true;
        for(int i = 0; i < N; i++){
            if(canBomb(i)){
                allNotBomb = false;
                break;
            }
        }

        if(allNotBomb) break;

        for(int i = 0; i < N; i++){
            searchAndBomb(i);
        }
        for(int i = 0; i < N; i++){
            moveDown(i);
        }    
    }

    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] != 0) res++;
        }
    }
    
    cout << res;

    return 0;
}

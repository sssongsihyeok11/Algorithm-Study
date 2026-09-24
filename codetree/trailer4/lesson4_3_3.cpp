#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int bomb_cols[15];
int startIdx[200];


void move(int st_idx, int c, int bombrow){
    for(int i = bombrow; i > st_idx; i--){
        grid[i][c] = grid[i - 1][c];
        grid[i - 1][c] = 0;
    }

    startIdx[c] += 1;
}
void bomb(int c){

    grid[startIdx[c]][c] = 0;
    int val = grid[startIdx[c]][c];

    if(val == 1){
        startIdx[c] += 1;

        return;
    }
    //left
    for(int i = c - 1; i >= max(0, c - (val - 1)); i--){
        grid[startIdx[c]][i] = 0;
        if(startIdx[i] == startIdx[c]){
            startIdx[i] += 1;
        }
        else if(startIdx[i] < startIdx[c]){
            move(startIdx[i], i, startIdx[c]);
        }
    }
    //right 
    for(int i = c + 1; i <= min(n - 1, c + (val - 1)); i++){
        grid[startIdx[c]][i] = 0;
        if(startIdx[i] == startIdx[c]){
            startIdx[i] += 1;
        }
        else if(startIdx[i] < startIdx[c]){
            move(startIdx[i], i, startIdx[c]);
        }
    }
    //down

    
    for(int i = startIdx[c] + 1; i <= min(n - 1, startIdx[c] + (val - 1)); i++){
        grid[i][c] = 0;
    }

    startIdx[c] += val;

    return;
}

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] <<" ";
        }
        cout <<"\n";
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) startIdx[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

        }
    }

    for (int i = 0; i < m; i++) {
        cin >> bomb_cols[i];

        bomb(bomb_cols[i] - 1);
    }

    print();
    return 0;
}
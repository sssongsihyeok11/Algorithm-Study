#include <iostream>

using namespace std;

int grid[4][4];
bool alreadySum[4][4];
char dir;

void move(int row, int col){
    if(dir == 'U'){
        if(row > 0){
            if(grid[row - 1][col] != 0 && grid[row][col] != grid[row - 1][col]) return;
        }
        else return;
    }
    else if(dir == 'D'){
        if(row < 3){
            if(grid[row + 1][col] != 0 && grid[row][col] != grid[row + 1][col]) return;
        }
        else return;
    }
    else if(dir == 'L'){
        if(col > 0){
            if(grid[row][col - 1] != 0 && grid[row][col] != grid[row][col - 1]) return;
        }
        else return;
    }
    else{
        if(col < 3){
            if(grid[row][col + 1] != 0 && grid[row][col] != grid[row][col + 1]) return;
        }
        else return;
    }

    //grid[row - 1][col] : already moved
    if(dir == 'U'){
        if(grid[row - 1][col] == grid[row][col]){
            if(!alreadySum[row - 1][col]){
                grid[row - 1][col] *= 2;
                grid[row][col] = 0;
                alreadySum[row - 1][col] = true;
            } 
            return;
        }
        else{
            if(grid[row - 1][col] == 0){
                grid[row - 1][col] = grid[row][col];
                grid[row][col] = 0;
                move(row - 1, col);
            }
        }
    }
    else if(dir == 'D'){
        if(grid[row + 1][col] == grid[row][col]){
            if(!alreadySum[row + 1][col]){
                grid[row + 1][col] *= 2;
                grid[row][col] = 0;
                alreadySum[row + 1][col] = true;
            }
            return;
        }
        else{
            if(grid[row + 1][col] == 0){
                grid[row + 1][col] = grid[row][col];
                grid[row][col] = 0;
                move(row + 1, col);
            }
        }      
    }
    else if(dir == 'L'){
        if(grid[row][col - 1] == grid[row][col]){
            if(!alreadySum[row][col - 1]){
                grid[row][col - 1] *= 2;
                grid[row][col] = 0;
                alreadySum[row][col - 1] = true;
            } 
            return;
        }
        else{
            if(grid[row][col - 1] == 0){
                grid[row][col - 1] = grid[row][col];
                grid[row][col] = 0;
                move(row, col - 1);
            }
        }      
    }
    else{
        if(grid[row][col + 1] == grid[row][col]){
            if(!alreadySum[row][col + 1]){
                grid[row][col + 1] *= 2;
                grid[row][col] = 0;
                alreadySum[row][col + 1] = true;
            } 
            return;
        }
        else{
            if(grid[row][col + 1] == 0){
                grid[row][col + 1] = grid[row][col];
                grid[row][col] = 0;
                move(row, col + 1);
            }
        }      
    }
}
void moveUp(int col){
    for(int r = 1; r < 4; r++){
        if(grid[r][col] == 0) continue;
        move(r, col);
        
    }
}
void moveDown(int col){
    for(int r = 2; r >= 0; r--){
        if(grid[r][col] == 0) continue;
        move(r, col);
        
    }
}
void moveLeft(int row){
    for(int c = 1; c < 4; c++){
        if(grid[row][c] == 0) continue;
        move(row, c);
        
    }
}
void moveRight(int row){
    for(int c = 2; c >= 0; c--){
        if(grid[row][c] == 0) continue;
        move(row, c);
        
    }
}

void print(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << grid[i][j] <<" ";
        }
        cout <<"\n";
    }
}
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
            alreadySum[i][j] = false;
        }
    }

    cin >> dir;

    if(dir =='U') {
        for(int col = 0; col < 4; col++) moveUp(col);
    }
    else if(dir == 'D'){
        for(int col = 0; col < 4; col++) moveDown(col);
    }
    else if(dir == 'L'){
        for(int row = 0; row < 4; row++) moveLeft(row);
    }
    else {
        for(int row = 0; row < 4; row++) moveRight(row);
    }
    // Please write your code here.

    print();
    return 0;
}

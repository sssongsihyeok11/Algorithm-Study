#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] <<" ";
        }
        cout <<"\n";
    }
}

void CheckEmptyAndMove(){
    for(int r = 0; r < n; r++){
        bool flag = true;
        for(int c = k - 1; c < k - 1 + m ; c++){
            if(grid[r][c] == 1){
                flag = false;
                break;
            } 
        }

        if(flag){
            if(r > 0){
                for(int c = k - 1; c < k - 1 + m ; c++){
                    grid[r - 1][c] = 0;
                }     
            }
            for(int c = k - 1; c < k - 1 + m ; c++){
                grid[r][c] = 1;
            }     
        }
        else break;
    }
}


int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    CheckEmptyAndMove();

    print();
    return 0;
}

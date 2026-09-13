#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

bool canSpotBlock1_1(int r, int c){
    return(r + 1 < n && c + 1 < m);
}
bool canSpotBlock1_2(int r, int c){
    return(r + 1 < n && c - 1 >= 0);
}
bool canSpotBlock1_3(int r, int c){
    return(r - 1 >= 0 && c - 1 >= 0);
}
bool canSpotBlock1_4(int r, int c){
    return(r - 1 >= 0 && c + 1 < m);
}
bool canSpotBlock2_1(int r, int c){
    return(c + 2 < m);
}
bool canSpotBlock2_2(int r, int c){
    return (r + 2 < n);
}
int main() {
    cin >> n >> m;
    int tsum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum;
            if(canSpotBlock1_1(i, j)){
                sum = grid[i][j] + grid[i + 1][j] + grid[i + 1][j + 1];
                tsum = max(sum, tsum);
            }
            if(canSpotBlock1_2(i, j)){
                sum = grid[i][j] + grid[i + 1][j - 1] + grid[i][j - 1];
                tsum = max(sum, tsum);
            }
            if(canSpotBlock1_3(i, j)){
                sum = grid[i][j] + grid[i - 1][j] + grid[i - 1][j - 1];
                tsum = max(sum, tsum);
            }
            if(canSpotBlock1_4(i, j)){
                sum = grid[i][j] + grid[i][j + 1] + grid[i - 1][j + 1];
                tsum = max(sum, tsum);
            }
            if(canSpotBlock2_1(i, j)){
                sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                tsum = max(sum, tsum);
            }
            if(canSpotBlock2_2(i, j)){
                sum = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                tsum = max(sum, tsum);
            }
        }
    }

    cout << tsum;
    // Please write your code here.

    return 0;
}

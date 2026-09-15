#include <iostream>

using namespace std;

int n;
int grid[20][20];
int total_sum = 0;

void setRectangle(int r, int c, int sum, int start_r, int start_c, int dir, int cnt0, int cnt1, int cnt2,int cnt3){
    if(r == start_r && c == start_c && dir == 3){
        if(cnt0 >= 1 && cnt1 >= 1 && cnt2 >= 1 && cnt3 >=1) total_sum = max(total_sum, sum);
        return;
    }


    if(dir == 1){
        if(cnt0 == 0) return;
    }
    else if(dir == 2){
        if(cnt0 == 0 || cnt1 == 0)return;
    }
    else if(dir == 3){
        if(cnt0 == 0 || cnt1 == 0 || cnt2 == 0) return;
    }
    if(dir == 0){
        if(r - 1 >= 0 && c + 1 < n){
            setRectangle(r - 1, c + 1, sum + grid[r][c], start_r, start_c, dir, cnt0 + 1, cnt1, cnt2, cnt3);
        }
        dir = 1;
    }
    if(dir == 1){
        if(r - 1 >= 0 && c - 1 >= 0){
            setRectangle(r - 1, c - 1, sum + grid[r][c], start_r, start_c, dir, cnt0, cnt1 + 1, cnt2, cnt3);
        }
        dir = 2;        
    }
    if(dir == 2){
        if(r + 1 < n && c - 1 >= 0){
            setRectangle(r + 1, c - 1, sum + grid[r][c], start_r, start_c, dir, cnt0, cnt1, cnt2 + 1, cnt3);
        }
        dir = 3;
    }
    if(dir == 3){
        if(r + 1 < n && c + 1 < n){
            setRectangle(r + 1, c + 1, sum + grid[r][c], start_r, start_c, dir, cnt0, cnt1, cnt2, cnt3 + 1);
        }
        dir = 0;
    }

}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 2; i < n; i++){
        for(int j = 1; j < n - 1; j++){
            setRectangle(i, j, 0, i, j, 0, 0, 0, 0, 0);
        }
    }

    cout << total_sum;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
int a[100][100];

void move(int r1, int c1, int r2, int c2){
    int tmp1, tmp2, tmp3, tmp4;

    tmp1 = a[r1][c2];
    tmp2 = a[r2][c2];
    tmp3 = a[r2][c1];

    for(int i = c2; i > c1; i--){
        a[r1][i] = a[r1][i - 1];
    }

    for(int i = r2; i > r1 + 1; i--){
        a[i][c2] = a[i - 1][c2];
    }
    a[r1 + 1][c2] = tmp1;
    
    for(int i = c1; i < c2 - 1; i++){
        a[r2][i] = a[r2][i + 1];
    }
    a[r2][c2 - 1] = tmp2;

    for(int i = r1; i < r2 - 1; i++){
        a[i][c1] = a[i + 1][c1];
    }

    a[r2 - 1][c1] = tmp3;
}

void debug(int r1, int c1, int r2, int c2){
    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            cout << a[i][j] <<" ";
        }
        cout <<"\n";
    }
}

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] <<" ";
        }
        cout <<"\n";
    }
}

void setScore(int r1, int c1, int r2, int c2){
    vector<vector<int>> accu;
    accu.resize(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));
    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            int acc = a[i][j];
            int cnt = 1;
            if(i - 1 >= 0) {
                acc += a[i - 1][j];
                cnt++;
            }
            if(i + 1 < n) {
                acc += a[i + 1][j];
                cnt ++;
            }
            if(j - 1 >= 0) {
                acc += a[i][j - 1];
                cnt++;
            }
            if(j + 1 < m) {
                acc += a[i][j + 1];
                cnt++;
            }
            accu[i - r1][j - c1] = acc/cnt;
        }
    }

    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <= c2; j++){
            a[i][j] = accu[i - r1][j - c1];
        }
    }

}
int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        move(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
        setScore(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
    }
    print();
    // Please write your code here.

    return 0;
}

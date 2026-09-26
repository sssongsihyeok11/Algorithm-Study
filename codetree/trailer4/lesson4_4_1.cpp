#include <iostream>
#include <vector>
using namespace std;

int n;
int r, c;
int a[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<int> res;

void move(int r, int c){
    res.push_back(a[r][c]);

    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 1 || nr > n || nc < 1 || nc > n) continue;

        if(a[r][c] < a[nr][nc]){
            move(nr, nc);
            return;
        }
    }
    return;
}
void print(){
    for(int i = 0; i < res.size(); i++) cout << res[i] <<" ";
}
int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    move(r, c);

    print();
    return 0;
}
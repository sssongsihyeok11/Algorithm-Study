#include <iostream>
#include <vector>
using namespace std;

int n, m;
int grid[20][20];
vector<pair<int, int>> kind;

void setRectangle(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            kind.push_back({i, j});
        }
    }
}

bool isPlus(int sr, int sc, int er, int ec){
    for(int i = sr; i <= er; i++){
        for(int j = sc; j <= ec; j++){
            if(grid[i][j] <= 0) return false;
        }
    }

    return true;
}
int main() {
    cin >> n >> m;
    int res = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    setRectangle();

    for(int sr = 0; sr < n; sr++){
        for(int sc = 0; sc < m; sc++){
            for(int i = 0; i < kind.size(); i++){
                pair<int, int> l = kind[i];
                int er = sr + l.first;
                int ec = sc + l.second;

                if(er >= n || ec >= m) continue;

                if(isPlus(sr, sc, er, ec)){
                    res = max(res, (er - sr + 1)*(ec - sc + 1));
                }
            }
        }
    }
    // Please write your code here.
    cout << res;
    return 0;
}

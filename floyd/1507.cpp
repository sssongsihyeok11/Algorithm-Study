#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN 21

using namespace std;

int ret = 0;
int dist[MAXN][MAXN];
bool check[MAXN][MAXN];
int n;
bool floyd(int r, int c) {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (i == r || i == c) continue;
        if (dist[r][c] > dist[r][i] + dist[i][c]) return false;
        else if (dist[r][c] == dist[r][i] + dist[i][c]) { //다른 도로 2곳 찾음
            flag = true;
            break;
        }
    }

    if (!flag) { //유일한 도로
        check[r][c] = true;
        check[c][r] = true;

        ret += dist[r][c];
    }

    return true;
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    memset(check, false, sizeof(check));
}


void solution() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || check[i][j]) continue;

            if (!floyd(i, j)) {
                cout << -1;
                return;
            }
            else continue;
        }
    }

    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
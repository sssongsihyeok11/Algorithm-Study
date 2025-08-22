#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 1001
#define MAXM 1001
#define MAXP 10
#define r first
#define c second
using namespace std;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
char map[MAXN][MAXM];
bool visited[MAXN][MAXM];
int power[MAXP];
int bef[MAXP];
int region[MAXP];
queue<pair<int, int>> turn[MAXP];
int n, m, p;
void bfs(int num) {
    for (int i = 0; i < power[num]; i++) {
        int sz = turn[num].size();
        for (int j = 0; j < sz; j++) {
            pair<int, int> loc = turn[num].front(); turn[num].pop();

            for (int dir = 0; dir < 4; dir++) {
                int nr = loc.r + dr[dir];
                int nc = loc.c + dc[dir];

                if (nr < 1 || nr > n || nc < 1 || nc > m) continue;
                if (visited[nr][nc] || map[nr][nc] == '#') continue;
                if (map[nr][nc] == '.') {
                    region[num] += 1;
                    visited[nr][nc] = true;
                    map[nr][nc] = num + '0';
                    turn[num].push({ nr, nc });
                }
            }
        }
    }
}
void init() {
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> power[i];
        if (power[i] > max(m, n)) power[i] = max(m, n);
    }
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] >= '1' && map[i][j] <= '9') {
                int val = map[i][j] - '0';
                region[val] += 1;
                turn[val].push({ i, j });
                visited[i][j] = true;
            }
        }
    }
}


bool check() {
    for (int i = 1; i <= p; i++) {
        if (bef[i] != region[i]) return true;
    }

    return false;
}

void copy() {
    for (int i = 1; i <= p; i++) {
        bef[i] = region[i];
    }
}
void solution() {
    while (1) {
        for (int i = 1; i <= p; i++) {
            bfs(i);
        }

        if (!check()) break;
        else {
            copy();
            continue;
        }
    }


    for (int i = 1; i <= p; i++) {
        cout << region[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}
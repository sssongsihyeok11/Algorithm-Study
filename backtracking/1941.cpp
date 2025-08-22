#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 6
using namespace std;

vector<vector<char>> comb;
vector<char> tmp;
char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int ans = 0;

bool adj() {
    queue<pair<int, int>> q;
    for (int i = 0; i < 25; i++) {
        int r = i / 5;
        int c = i % 5;

        if (visited[r][c]) {
            q.push({ r, c });
            break;
        }
    }


    bool tmp_visited[MAXN][MAXN];
    memset(tmp_visited, false, sizeof(tmp_visited));
    tmp_visited[q.front().first][q.front().second] = true;

    int cnt = 1;
    while (!q.empty()) {
        pair<int, int> loc = q.front(); q.pop();
        int cr = loc.first;
        int cc = loc.second;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
            if (!visited[nr][nc] || tmp_visited[nr][nc]) continue;

            tmp_visited[nr][nc] = true;
            q.push({ nr, nc });
            cnt++;
        }
    }

    return cnt == 7;
}
void combination(int cnt, int idx) {
    if (cnt == 7 && adj()) {
        comb.push_back(tmp);
        return;
    }

    for (int i = idx; i < 25; i++) {
        int r = i / 5;
        int c = i % 5;
        if (!visited[r][c]) {
            visited[r][c] = true;
            tmp.push_back(map[r][c]);
            combination(cnt + 1, i + 1);
            tmp.pop_back();
            visited[r][c] = false;
        }
    }
}
void init() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
}

void solution() {
    int ans = 0;
    combination(0, 0);

    for (int i = 0; i < comb.size(); i++) {
        int s = 0, y = 0;
        for (int j = 0; j < comb[i].size(); j++) {
            if (comb[i][j] == 'S') s++;
            if (comb[i][j] == 'Y') y++;
        }

        if (s + y == 7 && s >= 4) ans++;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
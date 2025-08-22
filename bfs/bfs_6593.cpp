#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAXL 31
#define MAXR 31
#define MAXC 31

using namespace std;
int dr[6] = { 1, 0, 0, -1, 0, 0 };
int dc[6] = { 0, 1, 0, 0, -1, 0 };
int dl[6] = { 0, 0, 1, 0, 0, -1 };
int step[MAXL][MAXR][MAXC];
char map[MAXL][MAXR][MAXC];

struct loc {
    int l;
    int r;
    int c;
};
queue<loc> q;
int L, R, C;
loc E;
pair<int, bool> bfs() {
    loc sang = q.front();
    step[sang.l][sang.r][sang.c] = 0;
    while (!q.empty()) {
        loc cur = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int nl = cur.l + dl[i];
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (map[nl][nr][nc] == '#' || step[nl][nr][nc] != -1) continue;

            if (nl == E.l && nr == E.r && nc == E.c) {
                return { step[cur.l][cur.r][cur.c] + 1, true};
            }

            step[nl][nr][nc] = step[cur.l][cur.r][cur.c] + 1;
  
            loc tmp;
            tmp.l = nl;
            tmp.r = nr;
            tmp.c = nc;
            q.push(tmp);
        }
    }

    return { 0, false };
}

bool init() {
    cin >> L >> R >> C;
    if (L == 0 && R == 0 && C == 0) return false;

    while (!q.empty()) {
        q.pop();
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 'S') {
                    loc tmp;
                    tmp.l = i;
                    tmp.r = j;
                    tmp.c = k;
                    q.push(tmp);
                }

                if (map[i][j][k] == 'E') {
                    E.l = i;
                    E.r = j;
                    E.c = k;
                }
                step[i][j][k] = -1;
            }
        }
    }
    return true;
}

void solution() {
    pair<int, bool> ans = bfs();
    if (!ans.second) {
        cout << "Trapped!" << "\n";
    }
    else {
        cout << "Escaped in " << ans.first << " minute(s)." << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        bool ans = init();
        if (!ans) return 0;
        solution();
    }
}
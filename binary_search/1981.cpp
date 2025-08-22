#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#define MAXN 101

using namespace std;

int n;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int map[MAXN][MAXN];


bool bfs(int diff) {
    for (int start_val = 0; start_val + diff <= 200; start_val++) {
        int range_min = start_val;
        int range_max = start_val + diff;

        if (map[1][1] < range_min || map[1][1] > range_max) continue;

        bool visited[MAXN][MAXN];
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({ 1, 1 });
        visited[1][1] = true;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int cr = cur.first;
            int cc = cur.second;

            if (cr == n && cc == n) return true;  

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr < 1 || nr > n || nc < 1 || nc > n) continue;
                if (visited[nr][nc]) continue;

                if (map[nr][nc] < range_min || map[nr][nc] > range_max) continue;

                visited[nr][nc] = true;
                q.push({ nr, nc });
            }
        }
    }

    return false;
}

void init() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            
        }
    }
}

void solution() {
    int ans = 200; 
    int left = 0;             
    int right = 200;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (bfs(mid)) {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
    return 0;
}
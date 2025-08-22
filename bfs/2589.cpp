#include <iostream>
#include <algorithm>
#include <queue>
#define MAXN 51

using namespace std;

int n, m;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
char map[MAXN][MAXN];
int dist[MAXN][MAXN];
int ans = 0;
void init() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			dist[i][j] = -1;
		}
	}
}

void bfs(int i, int j) {
	dist[i][j] = 0;

	queue<pair<int, int>> q;
	q.push({ i, j });

	while (!q.empty()) {
		pair<int, int> loc = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = loc.first + dr[i];
			int nc = loc.second + dc[i];

			if (nr < 1 || nr > n || nc < 1 || nc > m) continue;
			if (map[nr][nc] == 'W' || dist[nr][nc] != -1) continue;

			dist[nr][nc] = dist[loc.first][loc.second] + 1;
			ans = max(ans, dist[nr][nc]);
			q.push({ nr, nc });
		}
	}
}


void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 'L') bfs(i, j);
			for (int r = 1; r <= n; r++) {
				for (int c = 1; c <= m; c++) {
					dist[r][c] = -1;
				}
			}
		}
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
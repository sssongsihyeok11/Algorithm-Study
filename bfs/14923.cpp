#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
#define MAXN 1001
#define MAXM 1001
#define INF 987654321
using namespace std;

int n, m;
int hx, hy;
int ex, ey;
int map[MAXN][MAXM];
int ans = INF;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
bool visited[MAXN][MAXM][2];
void bfs() {


	queue<tuple<int, int, int, int>> q;

	q.push({ hx, hy, 0, 0 }); //r, c, dist, 부순 갯수
	visited[hx][hy][0] = true;
	while (!q.empty()) {
		int cr = get<0>(q.front());
		int cc = get<1>(q.front());
		int cd = get<2>(q.front());
		int cb = get<3>(q.front()); q.pop();
		//cout << cr << " " << cc << " " << cd << " " << cb << "\n";
		if (cr == ex && cc == ey) {
			ans = min(ans, cd);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (nr < 1 || nr > n || nc < 1 || nc > m) continue;

			if (map[nr][nc] == 1) {
				if (cb == 1) continue;
				if (visited[nr][nc][1]) continue;
				else {
					visited[nr][nc][1] = true;
					q.push({ nr, nc, cd + 1, 1 });
				}
			}
			else {
				if (visited[nr][nc][cb]) continue;
				visited[nr][nc][cb] = true;
				q.push({ nr, nc, cd + 1, cb });
			}
		}
	}


	if (ans == INF) ans = -1;

	return;
}

void init() {
	cin >> n >> m;
	cin >> hx >> hy;
	cin >> ex >> ey;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}

void solution() {
	bfs();

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
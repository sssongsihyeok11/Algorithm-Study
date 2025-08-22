
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 51
#define R first
#define C second
using namespace std;

int n, m, g, r;
vector<pair<int, int>> candidate;
vector<vector<int>> permutation;
vector<int> tmp;
vector<int> arr;


int map[MAXN][MAXN];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int bfs() {
	queue<pair<int, int>> q;
	//0 : empty
	//1 : green
	//2 : red
	//3 : flower

	pair<int, int> step[MAXN][MAXN];
	int cnt = 0;
	for (int i = 0; i < candidate.size(); i++) {
		if (arr[i] == 0) continue;
		step[candidate[i].first][candidate[i].second] = { 0, arr[i] };
		q.push({ candidate[i].first, candidate[i].second });
	}
	while (!q.empty()) {
		pair<int, int>loc = q.front(); q.pop();
		if (step[loc.R][loc.C].second == 3) continue;
		for (int i = 0; i < 4; i++) {
			int nr = loc.R + dr[i];
			int nc = loc.C + dc[i];

			if (nr < 1 || nr > n || nc < 1 || nc > m) continue;
			if (map[nr][nc] == 0 || step[nr][nc].second == 3) continue;

			int color = step[loc.R][loc.C].second;
			if (step[nr][nc].second == 0) {
				step[nr][nc].first = step[loc.R][loc.C].first + 1;
				step[nr][nc].second = color;
				q.push({ nr, nc });
			}
			else if (step[nr][nc].second == 1) {
				if (step[loc.R][loc.C].second == 2 && step[nr][nc].first == step[loc.R][loc.C].first + 1) {
					cnt++;
					step[nr][nc].second = 3;
				}
			}
			else if (step[nr][nc].second == 2) {
				if (step[loc.R][loc.C].second == 1 && step[nr][nc].first == step[loc.R][loc.C].first + 1) {
					cnt++;
					step[nr][nc].second = 3;
				}
			}
		}
	}

	return cnt;
}

void init() {
	cin >> n >> m >> g >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) candidate.push_back({ i, j });
		}
	}

	arr.resize(candidate.size());
	//0 : empty
	//1 : green
	//2 : red
	//3 : flower
	for (int i = 0; i < g; i++) {
		arr[i] = 1;
	}
	for (int i = g; i < g + r; i++) {
		arr[i] = 2;
	}
	sort(arr.begin(), arr.end());
}

void solution() {
	int ans = 0;

	do {
		ans = max(ans, bfs());
	} while (next_permutation(arr.begin(), arr.end()));


	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
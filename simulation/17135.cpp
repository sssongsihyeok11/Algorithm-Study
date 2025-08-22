#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define MAXN 17
#define MAXM 17

using namespace std;

int n, m, d;
int ans = 0;
vector<int> tmp;
vector<vector<int>> comb;
int dist[MAXN][MAXM];
int map[MAXN][MAXM];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool all_die(int c_map[MAXN][MAXM]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c_map[i][j] == 1) return false;
		}
	}

	return true;
}


void init_dist() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = -1;
		}
	}
}

void combination(int idx) {
	if (tmp.size() == 3) {
		comb.push_back(tmp);
		return;
	}

	for (int i = idx; i <= m; i++) {
		tmp.push_back(i);
		combination(i + 1);
		tmp.pop_back();
	}
}

int set_distance(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

pair<int, int> select_target(int c_map[MAXN][MAXM], int attack) {
	int dist = 10000;
	pair<int, int> res;
	res.second = 1000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c_map[i][j] == 1) {
				int tmp = set_distance(n + 1, attack, i, j);
				if (tmp <= d && tmp < dist || (tmp == dist && j < res.second)) {
					dist = tmp;
					res = { i, j };
				}
			}
		}
	}

	return res;
}
void debug(int c_map[MAXN][MAXM]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << c_map[i][j] << " ";
		}
	}
}
void init() {
	cin >> n >> m >> d;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	combination(1);
}

void solution() {
	for (int i = 0; i < comb.size(); i++) {

		int c_map[MAXN][MAXM];

		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= m; c++) {
				c_map[r][c] = map[r][c];
			}
		}
		int cnt = 0;

		while (1) {
			set<pair<int, int>> s;
			for (int j = 0; j < comb[i].size(); j++) {
				pair<int, int> res = select_target(c_map, comb[i][j]);
				if (res.second == 1000) continue;
				s.insert(res);
				
			}

			cnt += s.size();

			for (auto it : s) {
				c_map[it.first][it.second] = 0;
			}

			for (int i = n; i >= 1; i--) {
				for (int j = 1; j <= m; j++) {
					c_map[i + 1][j] = c_map[i][j];
					c_map[i][j] = 0;
				}
			}

			if (all_die(c_map)) break;
		}

		ans = max(ans, cnt);
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
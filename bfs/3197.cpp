#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define MAXR 1505
#define MAXC 1505
#define r first
#define c second

using namespace std;

int R, C;
char map[MAXR][MAXC];
int step_l[MAXR][MAXC];
int step_r[MAXR][MAXC];
bool check[MAXR][MAXC];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> s1, s2, s1next, s2next;
queue<pair<int, int>> water, waternext;
void debug_map(int t) {
	cout << t << "th " << "\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void debug_step_l(int t) {
	cout << t << "th " << "\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << step_l[i][j] <<" ";
		}
		cout << "\n";
	}
}

void debug_step_r(int t) {
	cout << t << "th " << "\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << step_r[i][j] << " ";
		}
		cout << "\n";
	}
}
bool can_move(int t) {
	while (!s1.empty()) {
		pair<int, int> loc = s1.front(); s1.pop();

		bool flag = false;

		for (int i = 0; i < 4; i++) {
			int nr = loc.r + dr[i];
			int nc = loc.c + dc[i];

			if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
			if (map[nr][nc] == 'X' || step_l[nr][nc] != -1) continue;

			flag = true;
			if (step_r[nr][nc] != -1) return true;

			step_l[nr][nc] = t;
			s1.push({ nr, nc });
		}

		if (!flag) s1next.push({ loc });
	}

	//debug_step_l(t);
	while (!s2.empty()) {
		pair<int, int> loc = s2.front(); s2.pop();

		bool flag = false;

		for (int i = 0; i < 4; i++) {
			int nr = loc.r + dr[i];
			int nc = loc.c + dc[i];

			if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
			if (map[nr][nc] == 'X' || step_r[nr][nc] != -1) continue;

			flag = true;
			if (step_l[nr][nc] != -1) return true;

			step_r[nr][nc] = t;
			s2.push({ nr, nc });
		}

		if (!flag) s2next.push({ loc });
	}
	//debug_step_r(t);
	return false;
}

void melt() {
	while (!water.empty()) {
		pair<int, int> loc = water.front(); water.pop();

		for (int i = 0; i < 4; i++) {
			int nr = loc.first + dr[i];
			int nc = loc.second + dc[i];

			if (nr < 1 || nr > R || nc < 1 || nc > C)continue;

			if (map[nr][nc] == 'X') {
				map[nr][nc] = '.';
				waternext.push({ nr, nc });
			}
		}
	}
}
void init() {
	bool flag = false;
	cin >> R >> C;
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			step_l[i][j] = -1;
			step_r[i][j] = -1;

			if (map[i][j] == 'L') {
				if (flag == false) {
					step_l[i][j] = 0;
					s1.push({ i, j });
					flag = true;
				}
				else {
					step_r[i][j] = 0;
					s2.push({ i, j });
				}
				water.push({ i, j });
			}
			else if (map[i][j] == '.') {
				water.push({ i, j });
			}
		}
	}
}

void solution() {
	int t = 0;

	while(1) {
		if (can_move(t)) break;

		melt();

		s1 = s1next;
		s2 = s2next;
		water = waternext;
		while (!s1next.empty()) s1next.pop();
		while (!s2next.empty()) s2next.pop();
		while (!waternext.empty()) waternext.pop();
		t++;

		//debug_map(t);
	}

	cout << t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
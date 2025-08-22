#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1001

using namespace std;

vector<pair<int, pair<int, int>>> up;
vector<pair<int, pair<int, int>>> down;

int n, m;
int parent_up[MAXN]; //오르막 먼저
int parent_down[MAXN]; // 내리막 먼저
int maxVal = 0;
int minVal = 0;

int find(int x, int parent[MAXN]) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x], parent);
}

bool isSame(int a, int b, int parent[MAXN]) {
	return find(a, parent) == find(b, parent);
}

void uni(int a, int b, int parent[MAXN]) {
	int x = find(a, parent);
	int y = find(b, parent);

	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void init() {
	cin >> n >> m;
	m += 1;
	for (int i = 0; i <= n; i++) {
		parent_up[i] = i;
		parent_down[i] = i;
	}
	int st, ed, w;
	while (m--) {
		cin >> st >> ed >> w;
		if (w == 0) {
			up.push_back({ 1, {st, ed} });
		}
		else {
			down.push_back({ 0, {st, ed} });
		}
	}
}

void solution() {
	//maxVal 먼저
	for (int i = 0; i < up.size(); i++) {
		pair<int, pair<int, int>> loc = up[i];
		int u = loc.second.first;
		int v = loc.second.second;
		if (!isSame(u, v, parent_up)) {
			uni(u, v, parent_up);
			maxVal += 1;
		}
	}

	//나머진 내리막 길이므로 0으로 더해줘서 의미 x
	for (int i = 0; i < down.size(); i++) {
		pair<int, pair<int, int>> loc = down[i];
		int u = loc.second.first;
		int v = loc.second.second;
		if (!isSame(u, v, parent_down)) {
			uni(u, v, parent_down);
		}
	}

	for (int i = 0; i < up.size(); i++) {
		pair<int, pair<int, int>> loc = up[i];
		int u = loc.second.first;
		int v = loc.second.second;
		if (!isSame(u, v, parent_down)) {
			uni(u, v, parent_down);
			minVal += 1;
		}
	}

	cout << maxVal * maxVal - minVal * minVal;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
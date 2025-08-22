#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MAXN 100001

using namespace std;

unordered_map<int, unordered_map<int, unordered_map<int, int>>> bridge;

vector<pair<int, pair<int, int>>> v;

int n, q;
int parent[MAXN];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

bool isSame(int a, int b) {
	return find(a) == find(b);
}
void uni(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (y > x) {
		parent[y] = x;
	}
	else parent[x] = y;
}
void init() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		v.push_back({ x1, {x2, y} });
		bridge[x1][x2][y] = i;
	}

}

void solution() {
	sort(v.begin(), v.end()); 
	int max_right = v[0].second.first;
	int last_idx = bridge[v[0].first][v[0].second.first][v[0].second.second];

	for (int i = 1; i < n; ++i) {
		int curr_idx = bridge[v[i].first][v[i].second.first][v[i].second.second];
		if (v[i].first <= max_right) {
			uni(last_idx, curr_idx);
			max_right = max(max_right, v[i].second.first);
		}
		else {
			max_right = v[i].second.first;
		}
		last_idx = curr_idx;
	}
	int n1, n2;
	while (q--) {
		cin >> n1 >> n2;
		cout << isSame(n1, n2) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	solution();
}
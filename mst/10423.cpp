#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1001

using namespace std;

bool power[MAXN];
int parent[MAXN];

int n, m, k;
vector<pair<int, pair<int, int>>> edge;
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

	if (power[x] || power[y]) {
		power[x] = power[y] = true;
	}

	if (y > x) {
		parent[y] = x;
	}
	else parent[x] = y;
}


void init() {
	cin >> n >> m >> k;
	fill(power, power + n + 1, false);
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < k; i++) {
		int v;
		cin >> v;
		power[v] = true;
		parent[v] = v;
	}

	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		edge.push_back({ w, {u, v} });
	}

	sort(edge.begin(), edge.end());
}

void solution() {
	long long ans = 0;
	
	for (int i = 0; i < edge.size(); i++) {
		pair<int, pair<int, int>> loc = edge[i];
		int u = loc.second.first;
		int v = loc.second.second;
		if (isSame(u, v)) continue;
		if (power[find(u)] && power[find(v)]) continue;
		
		uni(u, v);
		ans += loc.first;
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
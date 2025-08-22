#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100001

using namespace std;

int parent[MAXN];
long long visit_cost[MAXN];
int n, m;
long long ans = 987654321;
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

	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> visit_cost[i];
		ans = min(ans, visit_cost[i]);
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	int s, e, v;

	while (m--) {
		cin >> s >> e >> v;

		int w1 = visit_cost[s] + v;
		int w2 = visit_cost[e] + v;

		edge.push_back({ w1 + w2, {s, e} });
	}

	sort(edge.begin(), edge.end());
}

void solution() {
	int cnt = 0;
	for (int i = 0; i < edge.size(); i++) {
		int u = edge[i].second.first;
		int v = edge[i].second.second;
		int w = edge[i].first;

		if (!isSame(u, v)) {
			uni(u, v);
			ans += w;
			cnt++;
		}

		if(cnt == n - 1) break;
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
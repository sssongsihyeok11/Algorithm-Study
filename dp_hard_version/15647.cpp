#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 300001

using namespace std;

vector<pair<int, long long>> adj[MAXN];
int sub[MAXN];
long long dist[MAXN];

int n;


void debug() {
	cout << "sub : ";
	for (int i = 1; i <= n; i++) {
		cout << sub[i] << " ";
	}
	cout << "\ndist : ";
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}

}
int set_child(int idx, int pa) {
	int& ret = sub[idx];

	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i].first;
		if (next == pa) continue;

		ret += (set_child(next, idx) + 1);
	}

	return ret;
}


long long dfs(int idx, int pa) {

	long long& ret = dist[idx];

	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i].first;
		long long d = adj[idx][i].second;

		if (next == pa) continue;

		ret += d * (sub[next] + 1) + dfs(next, idx);
	}

	return ret;
}

void reroot(int idx, int pa) {

	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i].first;
		long long d = adj[idx][i].second;
		if (next == pa) continue;
		dist[next] = dist[idx] - d * (sub[next] + 1) + d*(n - (sub[next] + 1));
		reroot(next, idx);
	}
}
void init() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
		sub[i] = -1;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		long long d;
		cin >> u >> v >> d;
		adj[u].push_back({ v, d });
		adj[v].push_back({ u, d });
	}
}

void solution() {
	set_child(1, -1);
	dfs(1, -1);
	reroot(1, -1);

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << "\n";
	}
	//debug();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	solution();
}
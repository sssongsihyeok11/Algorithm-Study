#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define MAXN 2505
#define INF LLONG_MAX
#define f first
#define s second

using namespace std;

int n, m;
int cost[MAXN];
long long dp[MAXN][MAXN];
vector<pair<int, int>> adj[MAXN];
priority_queue<pair<long long, pair<int, int>>> pq;

long long ans = INF;
void dijkstra() {
	pq.push({ 0, {1, cost[1]} });

	while (!pq.empty()) {
		int loc = pq.top().second.first;
		long long cur_cost = -pq.top().first;
		int w = pq.top().second.second;

		pq.pop();

		if (loc == n && ans > cur_cost) ans = cur_cost;
		if (dp[loc][w] < cur_cost) continue;
		for (int i = 0; i < adj[loc].size(); i++) {
			int next = adj[loc][i].first;
			int nd = adj[loc][i].second;

			int next_oil = min(w, cost[loc]);
			long long next_cost = cur_cost + nd * next_oil;

			if (dp[next][next_oil] > next_cost) {
				dp[next][next_oil] = next_cost;
				pq.push({ -next_cost, {next, next_oil} });
			}
		}
	}
}
void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < MAXN; j++) {
			dp[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	int s, e, w;
	while (m--) {
		cin >> s >> e >> w;

		adj[s].push_back({ e, w });
		adj[e].push_back({ s, w });
	}
}

void solution() {
	dijkstra();
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	solution();
}
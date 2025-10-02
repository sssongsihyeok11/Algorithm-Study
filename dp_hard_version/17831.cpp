#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 200001

using namespace std;

vector<int> graph[MAXN];
int point[MAXN];
long long dp[MAXN][2];

int n;
void debug() {
	for (int i = 1; i <= n; i++) {
		cout << i << "th : " << dp[i][0] << " " << dp[i][1] << "\n";
	}
}
void dfs(int idx) {
	long long sum = 0;

	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];

		dfs(next);

		dp[idx][0] += max(dp[next][1], dp[next][0]);
		sum += max(dp[next][1], dp[next][0]);
	}

	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];

		dp[idx][1] = max(dp[idx][1], sum - max(dp[next][0], dp[next][1]) + dp[next][0] + point[idx] * point[next]);
	}
}
void init() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int pa;
		cin >> pa;
		graph[pa].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		cin >> point[i];
	}
}

void solution() {
	dfs(1);
	debug();
	cout << max(dp[1][0], dp[1][1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
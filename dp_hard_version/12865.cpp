#include <iostream>
#include <algorithm>
#define MAXN 101
#define MAXK 100001


using namespace std;

int dp[MAXN][MAXK];
int weight[MAXN];
int val[MAXN];

int n, w;
void init() {
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> val[i];
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (j - weight[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + val[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][w];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
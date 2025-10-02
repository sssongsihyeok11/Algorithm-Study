#include <iostream>
#define MAXN 1001
using namespace std;

int n, c;
long long dp[MAXN];
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

void init() {
	dp[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) cnt++;
		}
		dp[i] = dp[i - 1] + 2 * cnt;
	}
}

void solution() {
	cout << dp[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	cin >> c;
	while (c--) {
		cin >> n;
		solution();
	}
}
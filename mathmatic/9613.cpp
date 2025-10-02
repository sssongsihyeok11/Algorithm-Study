#include <iostream>
#define MAXN 101
using namespace std;

int n, c;
long long dp[MAXN][MAXN];
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}


void solution() {
	int arr[MAXN];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	long long ans = 0;

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans += gcd(arr[i], arr[j]);
		}
	}

	cout << ans <<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c;
	while (c--) {
		cin >> n;
		solution();
	}
}
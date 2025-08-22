#include <iostream>
#include <algorithm>
#define MAXK 10001

using namespace std;
int k, n;
long long arr[MAXK];
long long r;
long long l;
void init() {
	cin >> k >> n;

	r = 0;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		r += arr[i];
	}
}

void solution() {
	l = 1;
	long long ans = 0;

	while (l <= r) {
		long long mid = l + (r - l) / 2;

		int cnt = 0;

		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt >= n) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
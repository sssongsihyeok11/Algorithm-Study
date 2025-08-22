#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 10005
using namespace std;

int arr[MAXN];

int n;

void init() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
}

void solution() {
	long long ans = 0;


	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			auto ub = upper_bound(arr + j + 1, arr + n, -arr[i] - arr[j]);
			auto lb = lower_bound(arr + j + 1, arr + n, -arr[i] - arr[j]);

			ans += ub - lb;
		}
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
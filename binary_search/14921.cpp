#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXN 100001

using namespace std;

long long ans = 1e18;
int n;

int arr[MAXN];

void init() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int left = 1, right = n;

	while (left < right) {
		long long sum = arr[left] + arr[right];


		if (sum < 0) left++;
		else if (sum == 0) {
			cout << 0;
			return;
		}
		else right--;


		if (abs(sum) < abs(ans)) {
			ans = sum;
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
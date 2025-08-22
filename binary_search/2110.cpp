#include <iostream>
#include <algorithm>
#define MAXN 200001

using namespace std;

int n, c;
int arr[MAXN];
void init() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
}

void solution() {
	int ret = 0;
	int left = 0;
	int right = arr[n - 1];

	while (left <= right) {
		int dist = left + (right - left) / 2;
		int cnt = 1;
		int prev = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] - prev >= dist) {
				prev = arr[i];
				cnt++;
			}
		}

		if (cnt >= c) {
			ret = max(ret, dist);
			left = dist + 1;
		}
		else right = dist - 1;
	}

	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
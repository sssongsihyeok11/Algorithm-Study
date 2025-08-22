//다시
#include <iostream>
#include <algorithm>

#define MAXN 2001
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
	int cnt = 0;
	for (int k = 0; k < n; k++) {
		int tar = arr[k];
		int i = 0, j = n - 1;

		while (i < j) {
			int sum = arr[i] + arr[j];

			if (sum == tar) {
				if (i == k) i++;
				else if (j == k) j--;
				else {
					cnt++;
					break;
				}
			}
			else if (sum < tar) {
				i++;
			}
			else j--;
		}
	}

	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
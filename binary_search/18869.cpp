#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 10002
#define MAXM 102

using namespace std;

int arr[MAXM][MAXN];
int n, m;


void compress(int a[]) {
	vector<int> v(a, a + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}
}

bool cmp(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) return false;
	}

	return true;
}
void init() {
	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}

		compress(arr[i]);
	}
}

void solution() {
	int ans = 0;
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			ans += cmp(arr[i], arr[j]);
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
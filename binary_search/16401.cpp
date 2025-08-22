#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> v;

int get_cnt(int val) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i] / val;
	}

	return cnt;
}
void init() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
}

void solution() {
	int left = 1, right = 1000000000;
	int ans = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		int cnt = get_cnt(mid);
		if (cnt >= m) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
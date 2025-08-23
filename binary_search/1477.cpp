#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, L;

vector<int> v;


int get_cnt(int diff) {
	if (diff == 0) return 2e9;

	int cnt = 0;

	cnt += (v[0] - 1) / diff;

	for (int i = 1; i < v.size(); i++) {
		int dist = v[i] - v[i - 1];
		cnt += (dist - 1) / diff;
	}

	return cnt;
}

void init() {
	cin >> n >> m >> L;

	int num;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		v.push_back(num);
	}
	v.push_back(L);

	sort(v.begin(), v.end());
}

void solution() {
	int left = 1; // 차이가 없다
	int right = L - 1; 
	int ans = L - 1; //최대 차이
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int check = get_cnt(mid);

		if (check <= m) { 
			ans = mid;
			right = mid - 1;
		}
		else { 
			left = mid + 1; 
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
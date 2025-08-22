#include <iostream>
#include <set>
#include <algorithm>
#define MAXN 100001
using namespace std;

multiset<pair<int, int>> s;
int arr[MAXN];
int n, n_cmd, cmd;

void init() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		s.insert({ arr[i], i });
	}
}

void solution() {
	cin >> n_cmd;

	while (n_cmd--) {
		cin >> cmd;

		if (cmd == 1) {
			int idx, v;
			cin >> idx >> v;

			int prev = arr[idx];

			auto it = s.find({ prev, idx });

			s.erase(it);

			arr[idx] = v;

			s.insert({ v, idx });
		}
		else {
			cout << s.begin()->second << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	solution();
}
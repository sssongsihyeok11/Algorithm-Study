//이거 왜,,

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define MAXN 1000001

using namespace std;

int parent[MAXN];

int n, m;
vector<pair<int, int >> v;

void init() {
	cin >> n;
	cin >> m;
	int x1, x2;
	while (m--) {
		cin >> x1 >> x2;
		v.push_back({ x1, x2 });
	}
}

void solution() {
	if (v.empty()) {
		cout << n;
		return;
	}
	sort(v.begin(), v.end());

	int left = v[0].first;
	int right = v[0].second;
	int removed = 0;

	for (int i = 1; i < v.size(); i++) {
		if (right >= v[i].second) {

			continue;
		}
		else if (v[i].first <= right) {

			right = v[i].second;
		}
		else {

			removed += (right - left);
			left = v[i].first;
			right = v[i].second;
		}
	}

	removed += (right - left);

	cout << n - removed;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
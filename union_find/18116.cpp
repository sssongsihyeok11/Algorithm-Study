#include <iostream>
#include <algorithm>
#define MAXN 1000001

using namespace std;

int parent[MAXN];
int group_cnt[MAXN];
int n;

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

bool isSame(int a, int b) {
	int x = find(a);
	int y = find(b);

	return x == y;
}

void uni(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return;
	if (x > y) {
		parent[x] = y;
		group_cnt[y] += group_cnt[x];
	}
	else {
		parent[y] = x;
		group_cnt[x] += group_cnt[y];
	}
}

void init() {
	cin >> n;
	for (int i = 1; i < MAXN; i++) {
		parent[i] = i;
		group_cnt[i] = 1;
	}
}

void solution() {
	char cmd;
	int a, b;

	while (n--) {
		cin >> cmd;
		if (cmd == 'I') {
			cin >> a >> b;
			uni(a, b);
		}
		else {
			cin >> a;
			
			cout << group_cnt[find(a)] << "\n";
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
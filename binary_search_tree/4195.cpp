#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MAXN 200005

using namespace std;

int idx = 0;

int t, f;

unordered_map<string, int> friend_idx;
unordered_map<int, int> get_cnt;
int parent[MAXN];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

bool is_Same(int a, int b) {
	return find(a) == find(b);
}

void uni(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x > y) {
		parent[x] = y;
		get_cnt[y] += get_cnt[x];
	}
	else {
		parent[y] = x;
		get_cnt[x] += get_cnt[y];
	}
}


void init() {
	cin >> f;
	for (int i = 1; i < MAXN; i++) parent[i] = i;
	idx = 0;
	friend_idx.clear();
	get_cnt.clear();
	
}

void solution() {
	while (f--) {
		string str1, str2;
		cin >> str1 >> str2;

		if (friend_idx.find(str1) == friend_idx.end() && friend_idx.find(str2) == friend_idx.end()) {
			friend_idx[str1] = idx++;
			friend_idx[str2] = idx++;

			int idx1 = friend_idx[str1];
			int idx2 = friend_idx[str2];

			get_cnt[idx1] = 1;
			get_cnt[idx2] = 1;

			uni(idx1, idx2);

			cout << get_cnt[find(idx1)] << "\n";
		}
		else if (friend_idx.find(str1) != friend_idx.end() && friend_idx.find(str2) == friend_idx.end()) {
			friend_idx[str2] = idx++;
			int idx1 = friend_idx[str1];
			int idx2 = friend_idx[str2];

			get_cnt[idx2] = 1;

			uni(idx1, idx2);

			cout << get_cnt[find(idx1)] << "\n";
		}
		else if(friend_idx.find(str1) == friend_idx.end() && friend_idx.find(str2) != friend_idx.end()) {
			friend_idx[str1] = idx++;
			int idx1 = friend_idx[str1];
			int idx2 = friend_idx[str2];

			get_cnt[idx1] = 1;

			uni(idx1, idx2);

			cout << get_cnt[find(idx2)] << "\n";
		}
		else {
			int idx1 = friend_idx[str1];
			int idx2 = friend_idx[str2];

			if (!is_Same(idx1, idx2)) {
				uni(idx1, idx2);
			}

			cout << get_cnt[find(idx1)] << "\n";
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		init();
		solution();
	}
}

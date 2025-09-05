#include <iostream>
#include <queue>
#define MAXK 5000001

using namespace std;

int n;
int elem[MAXK];

void init() {
	cin >> n;

	for (int i = 2; i < MAXK; i++) {
		if (elem[i] != 0) continue;

		int tmp = i;
		while (tmp < MAXK) {
			elem[tmp] = i;
			tmp += i;
		}
	}
}

void solution() {
	int val;
	while (n--) {
		cin >> val;

		priority_queue<int, vector<int>, greater<int>> q;
		while (val != 1) {
			int div_elem = elem[val];
			q.push(div_elem);
			val = val / div_elem;
		}


		while (!q.empty()) {
			cout << q.top() <<" "; q.pop();
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout.tie(NULL);

	init();
	solution();
}
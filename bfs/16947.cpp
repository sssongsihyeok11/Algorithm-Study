#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 3001

using namespace std;

int n;

vector<int> adj[MAXN];
queue<pair<int, int>>q;
int degree[MAXN];
bool isCircular[MAXN];
bool visited[MAXN];
int dp[MAXN];
int root;
bool find_circular(int idx, int p) {
	
	visited[idx] = true;
	bool& ret = isCircular[idx];

	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		
		if (next == p) continue;
		//cout << next << "\n";
		if (next != p && visited[next]) {
			root = next;
			if (degree[idx] > 2) {
				q.push({ 0, idx });
			}
			return isCircular[idx] = true;
		}
		
		ret = find_circular(next, idx);
		if (ret) break;
	}

	if (ret && degree[idx] > 2) {
		q.push({ 0, idx });
	}
	if (ret && idx == root) {
		return false;
	}

	return ret;
}



void bfs() {
	while (!q.empty()) {
		int cnt = q.front().first;
		int cn = q.front().second; q.pop();
		//cout << cn << " " << cnt << "\n";
		for (int i = 0; i < adj[cn].size(); i++) {
			int next = adj[cn][i];

			if (isCircular[next]) continue;

			if (dp[next] == -1) {
				dp[next] = dp[cn] + 1;
				q.push({ dp[next], next });
			}
		}
	}
}
void init() {
	memset(visited, false, sizeof(visited));
	memset(isCircular, false, sizeof(isCircular));
	cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = -1;
	int n1, n2;

	for (int i = 0; i < n; i++) {
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);

		degree[n1]++;
		degree[n2]++;
	}
}


void solution() {

	//for (int i = 1; i <= n; i++) {
	//	cout << degree[i] << " ";
	//}
	//cout << "\n";
	find_circular(1, -1);


	for (int i = 1; i <= n; i++) {
	//	cout << isCircular[i] << " ";
		if (isCircular[i]) dp[i] = 0;
	}
	//cout << "\n";
	
	bfs();

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	solution();
}
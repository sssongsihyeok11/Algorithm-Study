#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN 10001

using namespace std;

int point[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];
int n;
int dp[MAXN][2]; //0 : 우수마을 x, 1 : 우수마을 o
void recursive(int n1, int start) {
    if (adj[n1].size() == 1 && n1 != start) {
        dp[n1][0] = 0;
        dp[n1][1] = point[n1];
        return;
    }

    dp[n1][0] = 0;
    dp[n1][1] = 0;
    visited[n1] = true;
    for (int i = 0; i < adj[n1].size(); i++) {
        int n2 = adj[n1][i];

        if (visited[n2]) continue;

        recursive(n2, start);

        dp[n1][0] += max(dp[n2][0], dp[n2][1]);
        dp[n1][1] += dp[n2][0]; //인접 x
    }

    dp[n1][1] += point[n1];
}
void init() {
    cin >> n;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        cin >> point[i];
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    for (int i = 0; i < n - 1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}

void solution() {
    if (n == 1) cout << point[1];

    else {
        recursive(1, 1);
        cout << max(dp[1][0], dp[1][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 100001
#define MAXK 1001
#define MAXM 1001
using namespace std;

int n, k, m;
vector<int> adj[MAXN + MAXM];
int dp[MAXN + MAXM];
void init() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n + m; i++) {
        dp[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            int st;
            cin >> st;

            adj[st].push_back(n + i);
            adj[n + i].push_back(st);
        }
    }
}

void solution() {
    dp[1] = 1;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cn = q.front(); q.pop();

        for (int i = 0; i < adj[cn].size(); i++) {
            int next = adj[cn][i];

            if (dp[next] != -1) continue;
            if (next > n) {
                dp[next] = dp[cn];
            }
            else {
                dp[next] = dp[cn] + 1;
            }
            if (next == n) break;
            q.push(next);
        }
    }

    cout << dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
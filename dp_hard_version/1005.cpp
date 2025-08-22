#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1001

using namespace std;

int t[MAXN];
vector<int> adj[MAXN];

int T, n, m, target;
int dp[MAXN];
int degree[MAXN];
bool flag = false;
void topologySort(queue<int>& q) {
    while (1) {
        if (q.empty()) break;

        int cn = q.front(); q.pop();

        for (int i = 0; i < adj[cn].size(); i++) {
            int next = adj[cn][i];
            dp[next] = max(dp[next], dp[cn]);
            degree[next] -= 1;
            if (degree[next] == 0) {
                q.push(next);
                dp[next] += t[next];
            }
        }
    }
}
void init() {
    flag = false;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        degree[i] = 0;
        dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        if(t[i] != 0) flag = true;
    }

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        degree[n2]++;
    }
    cin >> target;
}

void solution() {
    if(flag == false){
        cout << 0 <<"\n";
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
            dp[i] = t[i];
        }
    }

    topologySort(q);

    cout << dp[target] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        init();
        solution();
    }
}
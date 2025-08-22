#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 100001

using namespace std;

int n, m, k;
vector<pair<long long, int>> adj[MAXN];
long long dist[MAXN];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

void dijkstra() {
    while (!pq.empty()) {
        pair<long long, int> d = pq.top(); pq.pop();

        int cn = d.second;
        long long cd = d.first;


        if (dist[cn] != cd) continue;

        for (int i = 0; i < adj[cn].size(); i++) {
            int next = adj[cn][i].second;
            long long distance = adj[cn][i].first;

            if (dist[next] > cd + distance) {
                dist[next] = cd + distance;
                pq.push({ dist[next], next });
            }
        }
    }
}
void debug() {
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}
void init() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        dist[i] = 1e18;
    }
    for (int i = 0; i < m; i++) {
        long long s, e, c;
        cin >> s >> e >> c;
        adj[e].push_back({ c, s });
    }
    int c;
    while (k--) {
        cin >> c;
        dist[c] = 0;
        pq.push({ dist[c], c });
    }
}

void solution() {
    dijkstra();

    //debug();

    long long ans = 0;
    int idx = -1;

    for (int i = 1; i <= n; i++) {
        if (ans < dist[i]) {
            idx = i;
            ans = dist[i];
        }
    }

    cout << idx << "\n" << dist[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
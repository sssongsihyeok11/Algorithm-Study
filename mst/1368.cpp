#include <iostream>
#include <algorithm>
#define MAXN 301
#define MAXE (MAXN * MAXN / 2 + MAXN) 

using namespace std;

int n;
int parent[MAXN];
int edge_count = 0;
pair<int, pair<int, int>> edge[MAXE]; 

int ans = 987654321;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool isSame(int a, int b) {
    return find(a) == find(b);
}

void uni(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x > y) parent[x] = y;
    else parent[y] = x;
}

void init() {
    cin >> n;
    for (int i = 0; i <= n; i++) parent[i] = i;

    int val;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        edge[edge_count++] = { val, {0, i} };
    }

    int cost;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost;
            if (i < j) {
                edge[edge_count++] = { cost, {i, j} };
            }
        }
    }

    sort(edge, edge + edge_count);
}

void solution() {
    int cnt = 0;
    for (int i = 0; i < edge_count; i++) {
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        int w = edge[i].first;

        if (!isSame(u, v)) {
            uni(u, v);
            ans += w;
            cnt++;
        }

        if (cnt == n - 1) break; 
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solution();
    return 0;
}

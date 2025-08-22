#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 8

using namespace std;

bool broken[MAXN];
int stability[MAXN];
int weight[MAXN];
int n;
int ans = 0;

void dfs(int idx) {

    if (idx == n ) {
        int tmp = 0;

        for (int i = 0; i < n; i++) {
            if (stability[i] <= 0) tmp++;
        }

        ans = max(ans, tmp);
        return;
    }

    if (stability[idx] <= 0) {
        dfs(idx + 1);
        return;
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        if (stability[i] > 0) {
            flag = true;
            break;
        }
    }

    if (!flag) {
        dfs(idx + 1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i == idx || stability[i] <= 0) continue;
        stability[idx] -= weight[i];
        stability[i] -= weight[idx];

        dfs(idx + 1);

        stability[idx] += weight[i];
        stability[i] += weight[idx];
    }
}
void init() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stability[i] >> weight[i];
    }
}

void solution() {
    dfs(0);

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
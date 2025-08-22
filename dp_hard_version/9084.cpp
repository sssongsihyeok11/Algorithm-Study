#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 21
#define MAXM 10001
using namespace std;

int t, n, m;

int coin[MAXN];
int dp[MAXN][MAXM];

void knacksack_problem() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 0;
            if (i - 1 >= 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j - coin[i] >= 0) {
                dp[i][j] += dp[i][j - coin[i]];
            }
        }
    }

    cout << dp[n - 1][m] << "\n";
}

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        dp[i][0] = 1;
    }
    cin >> m;
}

void solution() {
    knacksack_problem();
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
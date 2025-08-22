#include <iostream>
#include <algorithm>
#define MAXN 1005
#define MAXM 1005

using namespace std;

string str1, str2;
int dp[MAXN][MAXM];


void init() {
    cin >> str1;
    cin >> str2;

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXM; j++) {
            dp[i][j] = 0;
        }
    }
}

void solution() {
    int n = str1.size();
    int m = str2.size();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            dp[i][j] = max({ dp[i][j], dp[i - 1][j], dp[i][j - 1] });
        }
    }

    cout << dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
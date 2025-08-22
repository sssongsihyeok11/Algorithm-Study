#include <iostream>
#define MAXN 2001

using namespace std;

int arr[MAXN];
int dp[MAXN][MAXN];
int n, m;

void palindrome(int st, int ed) {
    int len = ed - st + 1;
    if (len == 2 || st == ed) {
        if (arr[st] == arr[ed]) {
            dp[st][ed] = true;
            return;
        }
        else {
            dp[st][ed] = false;
            return;
        }
    }

    if (dp[st][ed] != -1) return;

    palindrome(st + 1, ed - 1);

    if (dp[st + 1][ed - 1] == true && arr[st] == arr[ed]) {
        dp[st][ed] = true;
    }
    else dp[st][ed] = false;

    return;
}

void init() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = true;
    }
    cin >> m;
}

void solution() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dp[i][j] == -1) palindrome(i, j);
        }
    }


    for (int i = 0; i < m; i++) {
        int st, ed;
        cin >> st >> ed;
        cout << dp[st][ed] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}
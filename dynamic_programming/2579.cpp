#include <iostream>
#include <algorithm>
#define MAXN 301


using namespace std;
int n;
int arr[MAXN];
int dp[MAXN][3];
void init() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1][1] = arr[1];
    dp[1][2] = 0;
    dp[2][1] = arr[2];
    dp[2][2] = arr[1] + arr[2];
}

void solution() {
    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
        dp[i][2] = dp[i - 1][1] + arr[i];
    }

    cout << max(dp[n][1], dp[n][2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 100001

using namespace std;

int n;
int dp[MAXN];


int get_dp(int n) {
    if (pow((int)(sqrt(n)), 2) == n) {
        return dp[n] = 1;
    }

    int& ret = dp[n];
    if (ret != -1) return ret;

    ret = n;

    for (int i = 1; i * i <= n; i++) {
        ret = min(ret, get_dp(n - i * i) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) dp[i] = -1;
    cout << get_dp(n);
}
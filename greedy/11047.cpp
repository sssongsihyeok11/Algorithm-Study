#include <iostream>
#include <algorithm>
#define MAXN 11

using namespace std;

int n, k;
int arr[MAXN];

void init() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void solution() {
    int ans = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (k < arr[i]) {
            idx = i - 1;
            break;
        }
    }
    if (idx == 0) idx = n;
    while (idx != 0) {
        int d = k / arr[idx];
        ans += d;
        k -= d * arr[idx];

        idx--;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
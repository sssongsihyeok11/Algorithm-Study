#include <iostream>
#define MAXN 4000000
#define MOD 1000000007

using namespace std;

long long fact[MAXN + 1];
long long invFact[MAXN + 1];
long long n, k, m;

long long mod_pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long nCk(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;

    invFact[MAXN] = mod_pow(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    init();

    while (m--) {
        cin >> n >> k;
        cout << nCk(n, k) << "\n";
    }
}

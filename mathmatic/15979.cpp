#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m, n;
    cin >> m >> n;
    if(m < 0) m *= -1;
    if(n < 0) n *= -1;

    long long g = gcd(m, n);

    if (g == 0) cout << 0;
    else if (g == 1) cout << 1;
    else cout << 2;

    return 0;
}

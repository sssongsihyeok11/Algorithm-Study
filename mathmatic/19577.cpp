#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long n;

set<long long> get_tmp(long long n) {
    set<long long> answer;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            answer.insert(i);
            answer.insert(n / i);
        }
    }
  

    return answer;
}

long long phi(int x) {
    long long result = x;
    long long prime = 2;

    while (prime * prime <= x) {
        if (x % prime == 0) {
            while (x % prime == 0) {
                x = x / prime;
            }

            result -= result / prime;
        }

        prime += (prime == 2 ? 1 : 2);
    }

    if (x > 1) result -= result / x;

    return result;
}
void init() {
    cin >> n;
}

void solution() {
    set<long long> tmp = get_tmp(n);

    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        long long x = *it;

        long long Phi = phi(x);

        if (x*Phi == n) {
            cout << x;
            return;
        }
    }

    cout << -1;
}

int main() {
    init();
    solution();
}
#include <iostream>

using namespace std;

long long n;

long long phi(long long n) {
	long long result = n;
	long long p = 2;

	while (p * p <= n) {
		if (n % p == 0) {
			while (n % p == 0) n /= p;

			result -= result / p;
		}

		p += (p == 2 ? 1 : 2);
	}
	if (n > 1) result -= result / n;

	return result;
}

int main() {
	cin >> n;

	cout << phi(n);
}
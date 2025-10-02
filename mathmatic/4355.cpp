//9370다시
#include <iostream>
using namespace std;

long long n;

void init() {
	cin >> n;
}

void solution() {
	long long tmp = n;
	long long result = tmp;
	long long p = 2;

	while (p * p <= tmp) {
		if (tmp % p == 0) {
			while (tmp % p == 0) {
				tmp /= p;
			}

			result -= result / p;
		}

		p += (p == 2 ? 1 : 2);
	}

	if (tmp > 1) result -= result / tmp;

	if (n == 1) result = 0;
	cout << result <<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		init();
		if (n == 0) break;
		solution();
	}
}


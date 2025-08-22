#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1001
#define MAXM 1001
using namespace std;


int n, m;
long long t;
vector<long long> a_sum;
vector<long long> b_sum;
int A[MAXN];
int psumA[MAXN];
int B[MAXM];
int psumB[MAXM];
void init() {
	cin >> t;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		a_sum.push_back(A[i]);
		psumA[i] = psumA[i - 1] + A[i];
	}

	cin >> m;

	for (int i = 1; i <=m; i++) {
		cin >> B[i];
		b_sum.push_back(B[i]);
		psumB[i] = psumB[i - 1] + B[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			a_sum.push_back(psumA[j] - psumA[i - 1]);
		}
	}


	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			b_sum.push_back(psumB[j] - psumB[i - 1]);
		}
	}

	sort(a_sum.begin(), a_sum.end());

	//for (int i = 0; i < a_sum.size(); i++) {
	//	cout << a_sum[i] << " ";
	//}
	//cout << "\n";


	//for (int i = 0; i < b_sum.size(); i++) {
	//	cout << b_sum[i] << " ";
	//}
	//cout << "\n";
}

void solution() {
	long long ans = 0;

	for (int i = 0; i < b_sum.size(); i++) {
		long long tmp = b_sum[i];

		auto ub = upper_bound(a_sum.begin(), a_sum.end(), t - tmp);
		auto lb = lower_bound(a_sum.begin(), a_sum.end(), t - tmp);

		//cout << tmp << " " << ub - lb << "\n";
		ans += (ub - lb);
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	init();
	solution();
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, ed;
        cin >> st >> ed;
        v.push_back({ st, ed });
    }

    sort(v.begin(), v.end(), cmp);
}

void solution() {
    int ans = 1;
    int idx = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[idx].second <= v[i].first) {
            idx = i;
            ans++;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}

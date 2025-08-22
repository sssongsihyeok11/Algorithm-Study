#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

void init(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
}

void solution(){
    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans, (n - i)*v[i]);
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
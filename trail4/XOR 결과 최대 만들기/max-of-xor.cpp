#include <iostream>
#include <vector>
using namespace std;

int n, m;
int A[20];
int res = 0;
vector<int> v;

void dfs(int idx){
    if(v.size() == m){
        int acc = v[0];

        for(int i = 1; i < v.size(); i++){
            acc = acc^v[i];
        }

        res = max(res, acc);

        return;
    }

    for(int i = idx + 1; i < n; i++){
        v.push_back(A[i]);
        dfs(i);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.

    dfs(-1);

    cout << res;
    return 0;
}
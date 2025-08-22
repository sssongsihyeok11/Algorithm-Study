#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;
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
    int prev = -1;
    for(int i = 0; i < v.size(); i++){
        if(prev != -1){
            v[i] += v[prev];
        }
        ans += v[i];

        prev = i;
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
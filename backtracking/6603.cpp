#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<vector<int>> comb;
vector<int> tmp;
int k;


void combination(int cnt, int idx){
    if(cnt == 6){
        comb.push_back(tmp);
        return;
    }

    for(int i = idx; i < v.size(); i++){
        tmp.push_back(v[i]);
        combination(cnt + 1, i + 1);
        tmp.pop_back();
    }
}

void init(){
    for(int i = 0; i < comb.size(); i++){
        comb[i].clear();
    }
    v.clear();
    cin >> k;
    
    for(int i = 0; i < k; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
}

void solution(){
    combination(0, 0);

    for(int i = 0; i < comb.size(); i++){
        for(auto it : comb[i]){
            cout << it <<" ";
        }
        cout <<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    if(k == 0) return;
    solution();
}
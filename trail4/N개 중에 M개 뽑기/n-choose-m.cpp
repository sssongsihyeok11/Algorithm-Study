#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<int> v;

void dfs(int sn){
    if(v.size() == M){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] <<" ";
        }
        cout <<"\n";
        return;
    }
    for(int i = sn + 1; i <= N; i++){
        v.push_back(i);
        dfs(i);
        v.pop_back();
    }
}
int main() {
    cin >> N >> M;

    // Please write your code here.
    dfs(0);
    return 0;
}

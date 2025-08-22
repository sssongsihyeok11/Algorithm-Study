#include <iostream>
#include <set>

using namespace std;

set<int> loc;
int n, q;
int cur = 0;
void init(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num == 1) loc.insert(i);
    }
}

void solution(){
    int cmd, l, x;
    while(q--){
        cin >> cmd;
        if(cmd ==1){
            cin >> l;
            auto it = loc.find(l - 1);
            if(it == loc.end()){
                loc.insert(l - 1);
            }
            else {
                loc.erase(it);
            }
        }
        else if(cmd == 2){
            cin >> x;
            if(x >= n){
                cur += (x%n);
            }
            else cur += x;

            cur %= n;
        }
        else{
            if(loc.empty()){
                cout << -1 <<"\n";
            }
            else{
                int distance = 0;
                auto it = loc.end();
                it--;
                if(*it < cur){
                    distance += n - cur;
                    it = loc.lower_bound(0);
                    distance += *it;
                }
                else{
                    it = loc.lower_bound(cur);
                    distance += (*it - cur);
                }

                cout << distance <<"\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}
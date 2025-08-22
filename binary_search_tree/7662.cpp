#include <iostream>
#include <set>

using namespace std;

multiset<int> q;
int iter, k;

void init(){
    q.clear();
    cin >> k;
}

void solution(){
    while(k--){
        char cmd;
        int num;
        cin >> cmd >> num;

        if(cmd == 'I'){
            q.insert(num);
        }
        else if(cmd =='D'){
            if(q.empty()) continue;
            if(num == 1){
                auto iter = q.end();
                iter--;
                q.erase(iter);
            }
            else{
                q.erase(q.begin());
            }
        }
    }

    if(q.empty()) cout <<"EMPTY" <<"\n";
    else{
        auto it = q.end();
        it--;
        cout << *it <<" " << *q.begin() <<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> iter;
    while(iter--){
        init();
        solution();
    }
}
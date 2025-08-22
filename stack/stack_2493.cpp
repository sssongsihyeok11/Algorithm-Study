#include <iostream>
#define MAXN 500005

using namespace std;

pair<int, int> stack[MAXN];
int N;
int pos = 0;

bool empty(){
    return pos == 0;
}

pair<int, int> top(){
    if(empty()){
        return {-1, -1};
    }

    return stack[pos - 1];
}
void push(int idx, int num){
    stack[pos++] = {idx, num};
}

void pop(){
    pos --;
}

void init(){
    cin >>N;
}

void solution(){
    for(int idx = 0; idx < N; idx++){
        int num;
        cin >> num;
        int ans = 0;

        if(empty()){
            cout << ans <<" ";
        }
        else{   
            while(!empty()){
                pair<int, int> tar = top();
                if(tar.second > num){
                    ans = tar.first + 1;
                    break;
                }
                else{
                    pop();
                }
            }

            cout << ans <<" ";
        }
        push(idx, num);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solution();
}
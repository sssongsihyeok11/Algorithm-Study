#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> A;
priority_queue<int> B;

int n;

void init(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        A.push(num);
    }

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        B.push(num);
    }
}

void solution(){
    int s = 0;

    while(!A.empty()){
        s += A.top()*B.top();
        A.pop(), B.pop();
    }

    cout << s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
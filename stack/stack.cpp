#include <iostream>
#include <string>
#define MAXN 10005

using namespace std;

int stack[MAXN];
int pos = 0;
int N;
void push(int num){
    stack[pos++] = num;
}

int top(){
    if(pos == 0){
        return -1;
    }

    return stack[pos - 1];
}
int pop(){
    if(pos == 0){
        return -1;
    }

    int ans = top();

    pos --;
    return ans;
}

int size(){
    return pos;
}

bool empty(){
    return (pos ==0);
}

void init(){
    cin >> N;
}

void solution(){
    for(int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;

        if(cmd.compare("push") == 0){
            int num;
            cin >> num;
            push(num);
        }
        else if(cmd.compare("pop") == 0){
            cout << pop() <<"\n";
        }
        else if(cmd.compare("size") == 0){
            cout << size() <<"\n";
        }
        else if(cmd.compare("empty")==0){
            cout << empty() <<"\n";
        }
        else{
            cout << top() <<"\n";
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
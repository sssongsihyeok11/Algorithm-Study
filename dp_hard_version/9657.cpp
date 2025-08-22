#include <iostream>
#define MAXN 1001

using namespace std;

int dp[MAXN];
int n;
void init(){
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    dp[6] = 1;

    for(int i = 7; i < MAXN; i++){
        if(dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1 ){
            dp[i] = 0;
        }
        else dp[i] = 1;
    }
}

void solution(){
    cin >> n;

    if(dp[n] == 1) cout <<"SK";
    else cout <<"CY";
}

int main(){
    init();
    solution();
}
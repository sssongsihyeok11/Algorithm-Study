#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A;
vector<char> v;
int cnt[26];

void rightmove(string &A){
    char tmp = A.back();

    for(int i = A.length() - 1; i > 0; i--){
        A[i] = A[i - 1];
    }

    A[0] = tmp;

    return;
}
void shift(int i, string &A){
    for(int idx = 0; idx < i; idx++){
        rightmove(A);
    }

    return;
}

void initialize(){
    v.clear();
    for(int i = 0; i < 26; i++) cnt[i] = 0;
}

void debug(){
    for(int i = 0; i < A.length(); i++){
        cout << A[i] <<" ";
    }
}

void runlengthEncoding(){
    if(A.length() == 1){
        v.push_back(A[0]);
        v.push_back('1');

        return;
    }
    for(int i = 0; i < A.length(); i++){
        if(i == 0){
            cnt[A[i] - 'a'] ++;
        }
        else{
            if(A[i] == A[i - 1]){
                cnt[A[i] - 'a'] ++;
            }
            else{
                v.push_back(A[i - 1]);
                v.push_back(cnt[A[i - 1] - 'a'] + '0');
                cnt[A[i - 1] - 'a'] = 0;
                cnt[A[i] - 'a'] = 1;
            }
        }
    }

    v.push_back(A.back());
    int count = cnt[A.back() - 'a'];
    if(count == 10){
        v.push_back('1');
        v.push_back('0');
    }
    else{
        v.push_back(count + '0');
    }
    return;
}
int main() {
    cin >> A;
    size_t res = 1000;
    for(int i = 0; i < A.length(); i++){
        initialize();
        if(i != 0) rightmove(A);
        runlengthEncoding();

        res = min(res, v.size());
    }

    cout << res;
    return 0;
}

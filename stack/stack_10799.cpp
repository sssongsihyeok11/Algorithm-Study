#include <iostream>
#include <string>
#include <stack>
#define MAXN 100005

using namespace std;

string str;
struct Data{
    int piece;
    bool isLaser = true;
};

stack<Data> st;

void solution(){
    getline(cin, str);
    int ans = 0;
    for(int i = 0; i < str.length(); i++){
        Data data;
        if(str[i] == '('){
            data.piece = 0;
        }
        else data.piece = 1;

        if(i == 0 || st.empty()){
            st.push(data);
        }
        else{
            Data &tar = st.top();
            //cout << tar.piece <<" " << data.piece <<"\n";
            if(tar.piece ==0){
                if(data.piece == 1){
                    st.pop();
                    if(tar.isLaser){
                        ans += st.size();
                    }
                    else ans +=1;
                }
                else{
                    tar.isLaser = false;
                    st.push(data);   
                }
            }
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}
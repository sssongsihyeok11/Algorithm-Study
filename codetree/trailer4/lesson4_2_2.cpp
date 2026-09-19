#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    // Please write your code here.

    for(int i = 0; i < t; i++){
        int tmp1 = l[n - 1];
        int tmp2 = r[n - 1];
        int tmp3 = d[n - 1];
        for(int j = n - 1; j > 0; j--){
            l[j] = l[j - 1];
            r[j] = r[j - 1];
            d[j] = d[j - 1];
        }

        l[0] = tmp3;
        r[0] = tmp1;
        d[0] = tmp2;
    }

    for(int i = 0; i < n; i++){
        cout << l[i] <<" ";
    }
    cout <<"\n";
    for(int i = 0; i < n; i++){
        cout << r[i] <<" ";
    }
    cout <<"\n";    
    for(int i = 0; i < n; i++){
        cout << d[i] <<" ";
    }
    return 0;
}

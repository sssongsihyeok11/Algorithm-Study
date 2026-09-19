#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];


bool sameValue(int top, int bottom){
    for(int i = 0; i < m; i++){
        if(a[top][i] == a[bottom][i]) return true;
    }

    return false;
}
void move(char d, int r, int start){
    if(r == -1 || r == n) return;

    int tmp;
    if(d== 'L'){
        tmp = a[r][m- 1];
        for(int i = m - 1; i > 0; i--){
            a[r][i] = a[r][i - 1];
        }
        a[r][0] = tmp;
    }
    else{
        tmp = a[r][0];
        for(int i = 0; i < m - 1; i++){
            a[r][i] = a[r][i + 1];
        }

        a[r][m - 1] = tmp;
    }

    char next = d == 'L' ? 'R' : 'L';

    if(r == start){
        if(sameValue(r - 1, r)) move(next, r - 1, start);
        
        if(sameValue(r, r + 1)) move(next, r + 1, start);
        
    }
    else if( r > start){
        if(sameValue(r, r + 1)) move(next, r + 1, start);
    }
    else{
        if(sameValue(r - 1, r)) move(next, r - 1, start);
    }

}
int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;

        move(d, r - 1, r - 1);
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] <<" ";
        }
        cout <<"\n";
    }

    return 0;
}

#include <iostream>

using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;
int start_idx = 0;

void deleteBlock(int s, int e){
    for(int i = start_idx + s; i <= start_idx + e; i++){
        blocks[i] = 0;
    }
}

void moveBlock(int s, int e){
    int tmp[100];

    for(int i = start_idx; i < start_idx + s; i++){
        tmp[i] = blocks[i];
    }

    int idx = e;

    for(int i = idx; i > idx - s; i--){
        blocks[start_idx + i] = tmp[start_idx + s - 1 - (idx - i)];
    }

    start_idx += e - (s - 1);
}

void checkBlock(){
    cout << n - start_idx  << "\n";

    for(int i = start_idx; i < n; i++){
        cout << blocks[i] <<"\n";
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    deleteBlock(s1 - 1, e1 - 1);
    moveBlock(s1 - 1, e1 - 1);

    deleteBlock(s2 - 1, e2 - 1);
    moveBlock(s2 - 1, e2 - 1);

    checkBlock();
    return 0;
}

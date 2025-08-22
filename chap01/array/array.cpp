#include <iostream>

using namespace std;
/*
void insert(int idx, int num, int arr[], int &len){
    for(int i = len; i > idx; i--){
        arr[i] = arr[i - 1];
    }

    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int &len){
    for(int i = idx; i < len - 1; i++){
        arr[i] = arr[i + 1];
    }

    len --;
}

void print(int arr[], int &len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    insert(3, 60, arr, len);
    print(arr, len);
    cout << "\n";

    erase(4, arr, len);
    print(arr, len);
}
*/
//memset 비추
//fill 함수 사용

//합이 100을 만족하는 서로다른 2개의 인덱스가 존재하는지 확인하는 함수
//arr : 0~1000

bool func(int arr[], bool freq[], int len){
    for(int i = 0; i < len; i++){
        int tar = 100 - arr[i];
        if(freq[tar]) return true;

        freq[arr[i]] = true;
    }

    return false;
}
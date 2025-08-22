#include <iostream>
using namespace std;

int main(){
    int N;
    cin  >> N;
    int i;
    for(i = 1; i <= N; i*=2){
        if(i*2 > N) {
            cout << i;
            return 0;
        }
    }

    cout << i;
    return 0;
}


// 512MB : 1.2억개의 int
// 256MB : 6000만개의 int
// char : 1byte = 8bit
// int : 4byte = 32bit
// long long : 8byte = 64bit

// float : sign(1), exponent(8), mantissa(23)
// double : sign(1), exponent(11), mantissa(52)
// 실수의 저장/연산에서는 반드시 오차가 발생한다.
// double에 longlong 범위의 정수를 함부로 넣으면 오차가 발생할 수 있다.
// 실수의 비교는 등호를 사용하면 안된다.
#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] <<" ";
        }
        cout <<"\n";
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    int r2, c2, r3, c3, r4, c4;
    
    r2 = r - 1 - m1;
    c2 = c - 1 + m1; 

    r3 = r2 - m2;
    c3 = c2 - m2;

    r4 = r3 + m3;
    c4 = c3 - m3;
   
    int r1 = r - 1;
    int c1 = c - 1;

    //cout << r1 <<" "<< c1 <<" "<< r2 <<" "<< c2 <<" "<< r3 <<" "<< c3 <<" "<< r4 <<" "<< c4<<"\n";
     
    int tmp1 = grid[r1][c1];
    int tmp2 = grid[r2][c2];
    int tmp3 = grid[r3][c3];
    int tmp4 = grid[r4][c4];

    //cout << tmp1 <<" "<< tmp2 <<" "<< tmp3 <<" "<< tmp4 <<"\n";
    //start rotation
   
    if(dir == 0){
        //cout << "start 1" <<"\n";
        for(int i = r2; i < r1; i++){
            int j = c2 - (i - r2);
            //cout << i <<" "<< j <<"\n"; 

            grid[i][j] = grid[i + 1][j - 1];
        }
        //cout << "start 2" <<"\n";
        
        for(int i = r3; i < r2; i++){
            int j = c3 - (r3 - i);

            //cout << i <<" "<< j <<"\n"; 

            grid[i][j] = grid[i + 1][j + 1];
        }
        
        grid[r2 - 1][c2 - 1] = tmp2;

        for(int i = r4; i > r3 + 1; i--){
            int j = c4 - (i - r4);
            grid[i][j] = grid[i - 1][j + 1];

        }
        grid[r3 + 1][c3 - 1] = tmp3;
        for(int i = r1; i > r4 + 1; i--){
            int j = c1 - (r1 - i);
            grid[i][j] = grid[i - 1][j - 1];
        }

        grid[r4 + 1][c4 + 1] = tmp4;
        

    }
    else{
        for(int i = r4; i < r1; i++){
            int j = c4 + (i - r4);

            grid[i][j] = grid[i + 1][j + 1];
        }

        for(int i = r3; i < r4 - 1; i++){
            int j = c3 - (i - r3);

            grid[i][j] = grid[i + 1][j - 1];
        }

        grid[r4 - 1][c4 + 1] = tmp4;

        for(int i = r2; i > r3 + 1; i --){
            int j = c2 - (r2 - i);

            grid[i][j] = grid[i - 1][j - 1];
        }
        grid[r3 + 1][c3 + 1] = tmp3;

        for(int i = r1; i > r2 + 1; i--){
            int j = c1 + (r1 - i);

            grid[i][j] = grid[i - 1][j + 1];
        }

        grid[r2 + 1][c2 - 1] = tmp2;
    }

    print();
    
    return 0;
}

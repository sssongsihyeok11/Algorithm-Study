#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int grid[20][20];
int dist[50]; // dist[i] = k : ith distance, k golds(accumulation) 
vector<pair<int, int>> v;



int cost(int k){
    return k*k + (k + 1)*(k + 1);
}

int distance(pair<int, int> &loc, int r, int c){

    //cout <<loc.first <<" " <<loc.second <<" " << r <<" " << c <<"\n";
    int r1 = loc.first - r > 0 ? loc.first - r : r - loc.first;
    int c1 = loc.second - c > 0 ? loc.second - c : c - loc.second;

    return r1 + c1;
}

void initdist(){
    for(int i = 0; i < 2*n; i++) dist[i] = 0;
}
void debug(int r, int c){
    //cout << r <<" "<< c <<"th dist" <<"\n";
    for(int i = 0; i < 2*n; i++){
        cout << dist[i] <<" ";
    }
    cout <<"\n\n";
}
void prefixsum(){
    for(int i = 1; i < 2*n; i++) dist[i] = dist[i] + dist[i - 1];
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1)v.push_back({i, j});
        }
    }

    int res = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            initdist();
            for(int num = 0; num < v.size(); num++){
                int d = distance(v[num], r, c);
                dist[d]++;
            }
            //debug(r, c);
            prefixsum();
            for(int k = 0; k <= 2*n; k++){
                int ct = cost(k);
                int tg = dist[k];

                if(tg*m - ct >= 0) res = max(res, tg);
            }
        }
    }

    cout << res;
    return 0;
}

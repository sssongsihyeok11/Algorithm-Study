#include <iostream>
#include <vector>
using namespace std;

int n, m;
int grid[5][5];
vector<pair<int, int>> kind;
void setVector(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            kind.push_back({i, j});
        }
    }
}
int main() {
    cin >> n >> m;
    int ans = -10000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    setVector();

    for(int r1 = 0; r1 < n; r1++){
        for(int c1 = 0; c1 < m; c1++){
            for(int k1 = 0; k1 < kind.size(); k1++){
                pair<int, int> l1 = kind[k1];
                int r1_len = l1.first;
                int c1_len = l1.second;

                if(r1 + r1_len >= n || c1 + c1_len >= m) continue;

                int sum1 = 0;
                for(int i1 = r1; i1 <= r1 + r1_len; i1++){
                    for(int j1 = c1; j1 <= c1 + c1_len; j1++){
                        sum1 += grid[i1][j1];
                    }
                }
                //bottom first rectangle
                int sum2;
                for(int r2 = r1 + r1_len + 1; r2 < n; r2++){
                    for(int c2 = 0; c2 < m; c2++){
                        for(int k2 = 0; k2 < kind.size(); k2++){
                            sum2 = 0;
                            pair<int, int> l2 = kind[k2];
                            int r2_len = l2.first;
                            int c2_len = l2.second;
                            if(r2 + r2_len >= n || c2 + c2_len >= m) continue;

                            for(int i2 = r2; i2 <= r2 + r2_len; i2++){
                                for(int j2 = c2; j2 <= c2 + c2_len; j2++){
                                    sum2 += grid[i2][j2];
                                }
                            }

                            ans = max(ans, sum1 + sum2);
                        }
                    }
                }


                for(int c2 = c1 + c1_len + 1; c2 < m; c2++){
                    for(int r2 = 0; r2 < n; r2++){
                        for(int k2 = 0; k2 < kind.size(); k2++){
                            sum2 = 0;
                            pair<int, int> l2 = kind[k2];
                            int r2_len = l2.first;
                            int c2_len = l2.second;
                            if(r2 + r2_len >= n || c2 + c2_len >= m) continue;

                            for(int i2 = r2; i2 <= r2 + r2_len; i2++){
                                for(int j2 = c2; j2 <= c2 + c2_len; j2++){
                                    sum2 += grid[i2][j2];
                                }
                            }

                            ans = max(ans, sum1 + sum2);
                        }
                    }
                }
            }
        }
    }
    
    cout << ans;

    return 0;
}

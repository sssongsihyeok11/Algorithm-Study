#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 9
#define MAXM 9

using namespace std;

int map[MAXN][MAXM];
int n, m;
vector<pair<int, int>> cctv;
vector<pair<int, int>> cctv_5;
vector<vector<int>> comb; 
vector<int> tmp;
int dr[4] = { 1, 0, -1, 0 }; 
int dc[4] = { 0, 1, 0, -1 };

void combination() {
    if (tmp.size() == cctv.size()) {
        comb.push_back(tmp);
        return;
    }

    for (int i = 0; i < 4; i++) {
        tmp.push_back(i);
        combination();
        tmp.pop_back();
    }
}

void light(pair<int, int> loc, int dir, int copy_map[MAXN][MAXM], int num) {
    int cr = loc.first, cc = loc.second;

    while (1) {
        int nr = cr + dr[dir];
        int nc = cc + dc[dir];

        if (nr < 1 || nr > n || nc < 1 || nc > m || copy_map[nr][nc] == 6) break;

        if (copy_map[nr][nc] == 0) copy_map[nr][nc] = -1; // 감시 영역 표시
        cr = nr;
        cc = nc;
    }
}

void cctv_5_light(pair<int, int> loc) {
    light(loc, 0, map, 5);  // 아래
    light(loc, 1, map, 5);  // 오른쪽
    light(loc, 2, map, 5);  // 위
    light(loc, 3, map, 5);  // 왼쪽
}

void cctv_light(int copy_map[MAXN][MAXM], int dir, int num, pair<int, int> loc) {
    if (num == 1) {
        light(loc, dir, copy_map, num);
    }
    else if (num == 2) {
        
        if (dir == 0 || dir == 2) {
            light(loc, 0, copy_map, num); 
            light(loc, 2, copy_map, num);
        }
        else { 
            light(loc, 1, copy_map, num); 
            light(loc, 3, copy_map, num); 
        }
    }
    else if (num == 3) {
        
        if (dir == 0) { 
            light(loc, 0, copy_map, num); 
            light(loc, 1, copy_map, num); 
        }
        else if (dir == 1) {
            light(loc, 1, copy_map, num); 
            light(loc, 2, copy_map, num);
        }
        else if (dir == 2) {
            light(loc, 2, copy_map, num); 
            light(loc, 3, copy_map, num);
        }
        else { 
            light(loc, 3, copy_map, num); 
            light(loc, 0, copy_map, num); 
        }
    }
    else if (num == 4) {
        
        if (dir == 0) { 
            light(loc, 0, copy_map, num); 
            light(loc, 1, copy_map, num);
            light(loc, 3, copy_map, num); 
        }
        else if (dir == 1) { 
            light(loc, 0, copy_map, num); 
            light(loc, 1, copy_map, num); 
            light(loc, 2, copy_map, num); 
        }
        else if (dir == 2) { 
            light(loc, 1, copy_map, num);
            light(loc, 2, copy_map, num); 
            light(loc, 3, copy_map, num);
        }
        else { 
            light(loc, 0, copy_map, num); 
            light(loc, 2, copy_map, num); 
            light(loc, 3, copy_map, num);
        }
    }
}

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];

            if (map[i][j] != 0 && map[i][j] != 6 && map[i][j] != 5) {
                cctv.push_back({ i, j });
            }
            if (map[i][j] == 5) {
                cctv_5.push_back({ i, j });
            }
        }
    }
}

void solution() {
    
    for (int i = 0; i < cctv_5.size(); i++) {
        cctv_5_light(cctv_5[i]);
    }

    combination();

    int ans = n * m;
    for (int i = 0; i < comb.size(); i++) {
        int tmp = 0;
        int copy_map[MAXN][MAXM];

        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                copy_map[r][c] = map[r][c];
            }
        }

        for (int j = 0; j < comb[i].size(); j++) {
            pair<int, int> loc = cctv[j];
            int num = map[loc.first][loc.second];
            int dir = comb[i][j];

            cctv_light(copy_map, dir, num, loc);
        }

        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                if (copy_map[r][c] == 0) tmp++;
            }
        }

        ans = min(ans, tmp);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
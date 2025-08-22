//다시

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 11

using namespace std;

int n, m, k;
int remain_amount[MAXN][MAXN];
int additive_amount[MAXN][MAXN];
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

vector<vector<vector<int>>> tree;

void spring_and_summer() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (tree[i][j].empty()) continue;

            sort(tree[i][j].begin(), tree[i][j].end());

            vector<int> alive;
            int dead_nutrient = 0;

            for (int age : tree[i][j]) {
                if (remain_amount[i][j] >= age) {
                    remain_amount[i][j] -= age;
                    alive.push_back(age + 1);
                }
                else {
                  
                    dead_nutrient += age / 2;
                }
            }

            tree[i][j] = alive;
            remain_amount[i][j] += dead_nutrient;
        }
    }
}

void autumn() {
    vector<pair<int, int>> new_trees; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (tree[i][j].empty()) continue;

            int breeding_count = 0;
            for (int age : tree[i][j]) {
                if (age % 5 == 0) {
                    breeding_count++;
                }
            }

            if (breeding_count > 0) {
               
                for (int dir = 0; dir < 8; dir++) {
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];

                    if (nr < 1 || nr > n || nc < 1 || nc > n) continue;

                    for (int cnt = 0; cnt < breeding_count; cnt++) {
                        new_trees.push_back({ nr, nc });
                    }
                }
            }
        }
    }

    // 새 나무들 추가
    for (auto pos : new_trees) {
        tree[pos.first][pos.second].push_back(1);
    }
}

void winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            remain_amount[i][j] += additive_amount[i][j];
        }
    }
}

void init() {
    cin >> n >> m >> k;

    tree.resize(n + 1, vector<vector<int>>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> additive_amount[i][j];
            remain_amount[i][j] = 5;
        }
    }

    int r, c, age;
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> age;
        tree[r][c].push_back(age);
    }
}

void solution() {
    for (int year = 0; year < k; year++) {
        spring_and_summer();
        autumn();
        winter();
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += tree[i][j].size();
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();

    return 0;
}
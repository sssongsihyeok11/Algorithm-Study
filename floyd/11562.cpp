#include <iostream>
#include <algorithm>
#define MAXN 255
#define INF 987654321
using namespace std;

int dist[MAXN][MAXN];
int road[MAXN][MAXN];
int n, m, k;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    road[i][j] = 0;
                }
            }
        }
    }
}

void debug_dist() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "I" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}


void debug_road() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (road[i][j] == INF) cout << "I" << " ";
            else cout << road[i][j] << " ";
        }
        cout << "\n";
    }
}

void get_road_num(int r, int c) {
    for (int i = 1; i <= n; i++) {
        road[r][c] = min(road[r][c], road[r][i] + road[i][c]);
    }
}

void init() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            road[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        road[i][i] = 0;
    }

    int st, ed, flag;

    while (m--) {
        cin >> st >> ed >> flag;
        if (flag) {
            road[st][ed] = 0;
            road[ed][st] = 0;
            dist[st][ed] = 1;
            dist[ed][st] = 1;
        }
        else {
            dist[st][ed] = 1;
            road[st][ed] = 0;
            road[ed][st] = 1;
        }
    }
}

void solution() {
    floyd();
    //cout << "distance" << "\n";
    //debug_dist();

    //cout << "-----------------------------" << "\n";
    //cout << "road" << "\n";
   
    while (1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (road[i][j] == INF) {
                    get_road_num(i, j);
                }
            }
        }
        
        bool flag = false;


        //debug_road();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (road[i][j] == INF) flag = true;
            }
        }


        if (!flag) break;
    }
   
    //debug_road();

    cin >> k;
    while (k--) {
        int st, ed;
        cin >> st >> ed;

        cout << road[st][ed] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}
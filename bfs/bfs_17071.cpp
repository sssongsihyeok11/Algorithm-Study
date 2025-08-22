#include <iostream>
#include <queue>
#include <vector>
#define MAXN 500000
using namespace std;
int visited[2][MAXN + 1], n, k, ok, ac = 1;


void bfs(int n1, int n2) {
    queue<int> q;
    visited[0][n1] = 1;

    q.push(n1);

    while (q.size()) {
        k += ac;
        if (k > MAXN) break;
        if (visited[ac % 2][k]) {
            ok = true;
            break;
        }

        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int x = q.front(); q.pop();
            for (int nx : {x + 1, x - 1, 2 * x}) {
                if (nx < 0 || nx > MAXN || visited[ac % 2][nx]) continue;
                visited[ac % 2][nx] = visited[(ac + 1) % 2][x] + 1;
                if (nx == k) {
                    ok = 1; break;
                }
                q.push(nx);
            }

            if (ok) break;
        }
        if (ok) break;
        ac++;
    }
}
void init() {
    cin >> n >> k;
    ok = false;
}
void solution() {
    if (n == k) {
        cout << 0;
        return;
    }

    bfs(n, k);

    if (ok) cout << ac;
    else cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();
}
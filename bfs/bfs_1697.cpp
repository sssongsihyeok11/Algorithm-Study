#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 100001

using namespace std;

bool visited[MAXN];
int step[MAXN];
int n, k;

void bfs() {
    step[n] = 0;
    queue<int> q;
    q.push(n);
    visited[n] = true;


    while (!q.empty()) {
        int cn = q.front(); q.pop();

        int next = cn - 1;
        if (next >= 0 && !visited[next]) {
            step[next] = step[cn] + 1;
            visited[next] = true;
            q.push(next);
        }
        next = cn + 1;
        if (next < MAXN && !visited[next]) {
            step[next] = step[cn] + 1;
            visited[next] = true;
            q.push(next);
        }
        next = cn*2;
        if (next < MAXN && !visited[next]) {
            step[next] = step[cn] + 1;
            visited[next] = true;
            q.push(next);
        }
    }
}
void init() {
    cin >> n >> k;
}

void solution() {
    bfs();
    cout << step[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    solution();
}
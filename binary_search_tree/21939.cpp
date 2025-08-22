#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

multiset<pair<int, int>> problem;
unordered_map<int, int> problem_map;
int n, m;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, level;
        cin >> num >> level;
        problem.insert({ level, num });
        problem_map[num] = level;
    }
}

void solution() {
    cin >> m;
    int x, p, l;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (str == "recommend") {
            cin >> x;
            if (x == 1) {
                auto it = problem.end();
                it--;
                cout << it->second << "\n";
            }
            else {
                cout << problem.begin()->second << "\n";
            }
        }
        else if (str == "add") {
            cin >> p >> l;
            problem.insert({ l, p });
            problem_map[p] = l;
        }
        else {
            cin >> p;
            int l = problem_map[p];
            auto it = problem.find({ l, p });
            problem.erase(it);
            problem_map.erase(p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solution();
}
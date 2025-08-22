#include <iostream>
#include <algorithm>
#define MAXN 501

using namespace std;

int height, width;

int map[MAXN][MAXN];

//debug
void debug() {
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void init() {
	cin >> height >> width;
	for (int i = 1; i <= width; i++) {
		int h;
		cin >> h;

		while (h > 0) {
			map[height + 1 - h][i] = 2;
			h--;
		}
	}
}

void solution() {
	
	for (int h = 1; h <= height; h++) {
		int st = -1, ed = -1;
		for (int w = 1; w <= width; w++) {
			if (map[h][w] == 2) {
				if(st == -1) st = w;
				else if (ed == -1) {
					if (w - st == 1) st = w;
					else {
						for (int tmp = st + 1; tmp < w; tmp++) {
							map[h][tmp] = 1;
						}
						st = w;
					}
				}
			}
			
		}
	}

	int cnt = 0;
	//debug
	//debug();
	
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			if (map[i][j] == 1) cnt++;
		}
	}

	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
}
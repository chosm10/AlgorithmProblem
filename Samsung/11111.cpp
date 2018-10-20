#include<iostream>
#include<queue>
#include<string>
using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;
int main(void) {
	cout << "Hello";

	cin >> n >> m;
	char map[1001][1001];
	bool check[1001][1001];
	pair<pair<int, int>, pair<int, int>> home; // x, y, cnt, used
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			tmp[j] = map[i][j];
			check[i][j] = false;
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;
	home = make_pair(make_pair(0, 0), make_pair(0, 0));
	q.push(home);
	check[home.first.second][home.first.first] = true;
	int px, py, nx, ny, cnt, used;  // used가 0이면 장애물 pass가능
	while (!q.empty()) {
		px = q.front().first.first; py = q.front().first.second;
		cnt = q.front().second.first; used = q.front().second.second;
		if (px == m - 1 && py == n - 1) {
			cout << cnt << "\n";
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = px + dx[i]; ny = py + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				continue;
			}
			if (!check[ny][nx] && map[ny][nx] != 'M') {
				if (map[ny][nx] == 'R') {
					check[ny][nx] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, used)));
				}
				else if (map[ny][nx] == 'H') {
					if (used == 0) {
						check[ny][nx] = true;
						q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, 1)));
					}
				}
			}
		}
	}
	cout << "-1\n";
	return 0;
}
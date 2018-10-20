#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, M;
int map[9][9];
int copyMap[9][9];
bool check[9][9];
int main(void) {

	cin >> N >> M;
	vector<pair<int, int>> v;
	vector<int> com;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				v.push_back(make_pair(j, i));
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		com.push_back(0);
	}
	for (int i = 0; i < v.size() - 3; i++) {
		com.push_back(1);
	}
	queue<pair<int, int>> q;
	pair<int, int> p;
	int x, y, nx, ny, cnt;
	int max = 0;
	do {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copyMap[i][j] = map[i][j];
				check[i][j] = false;
				if (copyMap[i][j] == 2) {
					check[i][j] = true;
					q.push(make_pair(j, i));
				}
			}
		}
		for (int i = 0; i < com.size(); i++) {
			if (com[i] == 0) {
				copyMap[v[i].second][v[i].first] = 1;
			}
		}
		while (!q.empty()) {
			p = q.front();
			x = p.first; y = p.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i]; ny = y + dy[i];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
					continue;
				}
				if (copyMap[ny][nx] == 0 && !check[ny][nx]) {
					check[ny][nx] = true;
					copyMap[ny][nx] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copyMap[i][j] == 0) {
					cnt++;
				}
			}
		}
		if (max < cnt) {
			max = cnt;
		}
	} while (next_permutation(com.begin(), com.end()));

	cout << max << "\n";
	return 0;
}
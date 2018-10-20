#include<iostream>
#include<queue>
#define MAX 51
using namespace std;
int N, M;
int map[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int changeD[4] = { 3, 0, 1, 2 };
int nx, ny, nd;
void dfs(int x, int y, int d) {
	check[y][x] = true;
	map[y][x] = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "----------------\n";
	for (int i = 0; i < 4; i++) {
		d = changeD[d];
		nx = x + dx[d]; ny = y + dy[d];
		if (!check[ny][nx]) {
			dfs(nx, ny, nd);
		}
	}
	if (map[y - dy[d]][x - dx[d]] == 1) {
		return;
	}
}
int main(void) {

	cin >> N >> M;
	pair<pair<int, int>, int> start;
	cin >> start.first.second >> start.first.first >> start.second;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				check[i][j] = true;
			}
		}
	}
	dfs(start.first.first, start.first.second, start.second);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
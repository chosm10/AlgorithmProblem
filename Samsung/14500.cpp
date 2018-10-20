#include<iostream>
#define MAX 501
using namespace std;
int N, M;
int map[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int result = 0;
void dfs(int x, int y, int cnt, int sum) {
	check[y][x] = true;
	if (cnt == 3) {
		if (result < sum + map[y][x]) {
			result = sum + map[y][x];
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (!check[ny][nx]) {
			dfs(nx, ny, cnt + 1, sum + map[y][x]);
			check[ny][nx] = false;
		}
	}
}
void finger() {
	int top, bottom, right, left;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			top = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			bottom = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			top = (top > bottom) ? top : bottom;
			if (top > result) {
				result = top;
			}
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			right = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
			left = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 1][j];
			right = (right > left) ? right : left;
			if (right > result) {
				result = right;
			}
		}
	}
}
int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	finger();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(j, i, 0, 0);
			check[i][j] = false;
		}
	}
	cout << result << "\n";
	return 0;
}
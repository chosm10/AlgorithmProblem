#include<iostream>
#include<vector>
#include<algorithm>
#define MAXW 13
#define MAXH 16
using namespace std;
int map[MAXH][MAXW];
int copy_map[MAXH][MAXW];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, W, H;
int minimum;
void bomb(int x, int y) {
	if (copy_map[y][x] != 0) {
		int tmp = copy_map[y][x];
		copy_map[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < tmp; j++) {
				int nx = x + dx[i] * j; int ny = y + dy[i] * j;
				if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
					continue;
				}
				if (copy_map[ny][nx] != 0) {
					bomb(nx, ny);
				}
			}
		}
	}
}
void play(int x) {
	int ny = 0;
	while (copy_map[ny][x] == 0) {
		ny += dy[3];
		if (ny >= H) {
			return;
		}
	}
	bomb(x, ny);
	int tmp = 0;
	for (int i = H - 2; i >= 0; i--) {
		for (int j = 0; j < W; j++) {
			if (copy_map[i][j] != 0) {
				tmp = copy_map[i][j];
				ny = i;
				copy_map[i][j] = 0;
				while (copy_map[ny + dy[3]][j] == 0) {
					ny += dy[3];
					if (ny >= H) {
						ny = H - 1;
						break;
					}
				}
				copy_map[ny][j] = tmp;
			}
		}
	}
}
void dfs(int cnt) {
	if (cnt == N) {
		int cntBlock = 0;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				if (copy_map[j][k] != 0) {
					cntBlock++;
				}
			}
		}
		if (minimum > cntBlock) {
			minimum = cntBlock;
		}
		return;
	}
	int copy_copy_map[MAXH][MAXW];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			copy_copy_map[i][j] = copy_map[i][j];
		}
	}
	for (int i = 0; i < W; i++) {
		play(i);
		dfs(cnt + 1);
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				copy_map[j][k] = copy_copy_map[j][k];
			}
		}
	}
}
int main(void) {

	int test_case, T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		minimum = MAXW * MAXH;
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				copy_map[j][k] = map[j][k];
			}
		}
		dfs(0);

		cout << "#" << test_case << " " << minimum << "\n";
	}

	return 0;
}
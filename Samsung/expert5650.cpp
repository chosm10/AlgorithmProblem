#include<iostream>
#include<vector>
#define MAX 104
using namespace std;
int board[MAX][MAX];
int N;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int nx, ny;
int cnt;
int result;
bool start;
vector<vector<pair<int, int>>> v(11);

int main(void) {

	int test_case, T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				board[i][j] = -2;
			}
		}
		for (int i = 6; i <= 10; i++) {
			v[i].clear();
		}
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				cin >> board[i][j];
				if (board[i][j] >= 6) {
					v[board[i][j]].push_back({ j, i });
				}
			}
		}
		result = 0;
		int x, y, d;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (board[i][j] == 0) {
					board[i][j] = -1; // 시작점을 -1로, 시작점과 블랙홀을 같이
					for (int k = 0; k < 4; k++) {
						cnt = 0;
						start = false;
						x = j; y = i; d = k;
						while (true) {
							if (board[y][x] == -1 && start) {
								if (result < cnt) {
									result = cnt;
								}
								break;
							}
							start = true;
							nx = x; ny = y;
							while (true) {
								nx += dx[d];
								ny += dy[d];
								if (board[ny][nx] != 0) {
									break;
								}
							}
							switch (board[ny][nx]) {
							case -2:
								cnt++;
								d = (d + 2) % 4;
								break;
							case 1:
								cnt++;
								switch (d) {
								case 0:
									d = 1;
									break;
								case 1:
								case 2:
									d = (d + 2) % 4;
									break;
								case 3:
									d = 2;
									break;
								}
								break;
							case 2:
								cnt++;
								switch (d) {
								case 0:
									d = 3;
									break;
								case 1:
									d = 2;
									break;
								case 2:
								case 3:
									d = (d + 2) % 4;
									break;
								}
								break;
							case 3:
								cnt++;
								switch (d) {
								case 0:
								case 3:
									d = (d + 2) % 4;
									break;
								case 1:
									d = 0;
									break;
								case 2:
									d = 3;
									break;
								}
								break;
							case 4:
								cnt++;
								switch (d) {
								case 0:
								case 1:
									d = (d + 2) % 4;
									break;
								case 2:
									d = 1;
									break;
								case 3:
									d = 0;
									break;
								}
								break;
							case 5:
								cnt++;
								d = (d + 2) % 4;
								break;
							case 6:
							case 7:
							case 8:
							case 9:
							case 10:
								int tmp = board[ny][nx];
								if (v[tmp][0] == make_pair(nx, ny)) {
									nx = v[tmp][1].first;
									ny = v[tmp][1].second;
								}
								else {
									nx = v[tmp][0].first;
									ny = v[tmp][0].second;
								}
								break;
							}
							x = nx; y = ny;
						}
					}
					board[i][j] = 0;
				}
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;
}
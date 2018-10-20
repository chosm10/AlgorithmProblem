#include<iostream>
#include<queue>
#include<map>
#define MAX 650
using namespace std;
int board[MAX][MAX];
int N, M, K;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
struct cell {
	pair<int, int> pos;
	int life;
	int sleep;
};
int main(void) {

	int test_case, T;
	cin >> T;
	int cnt;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;
		queue<cell> q;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				board[i][j] = 0;
			}
		}

		for (int i = 300; i < 300 + N; i++) {
			for (int j = 300; j < 300 + M; j++) {
				cin >> board[i][j];
				if (board[i][j] != 0) {
					q.push({ { j, i }, board[i][j], -board[i][j] });
				}
			}
		}

		cell front_cell;
		map<pair<int, int>, int> m;
		map<pair<int, int>, int> ::iterator iter;
		int qsize = 0;
		int nx, ny;
		for (int i = 0; i < K; i++) {
			m.clear();
			qsize = q.size();
			for (int j = 0; j < qsize; j++) {
				front_cell = q.front();
				q.pop();

				if (front_cell.sleep < front_cell.life) {
					if (front_cell.sleep == 0) {
						for (int k = 0; k < 4; k++) {
							nx = 0; ny = 0;
							nx = front_cell.pos.first + dx[k];
							ny = front_cell.pos.second + dy[k];

							if (board[ny][nx] == 0) {
								if (m.find({ nx, ny }) == m.end()) {
									m[{nx, ny}] = front_cell.life;
								}
								else {
									if (m[{nx, ny}] < front_cell.life) {
										m[{nx, ny}] = front_cell.life;
									}
								}
							}
						}
					}
					++front_cell.sleep;
					if (front_cell.sleep != front_cell.life) {
						q.push(front_cell);
					}
				}
			}

			for (iter = m.begin(); iter != m.end(); iter++) {
				board[iter->first.second][iter->first.first] = iter->second;
				q.push({ iter->first, iter->second, -iter->second });
			}
		}

		cnt = q.size();
		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;
}

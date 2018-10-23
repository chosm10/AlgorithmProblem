#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 12
using namespace std;
int N, M, K;
vector<int> board[MAX][MAX];
int energy[MAX][MAX];
int plus_energy[MAX][MAX];
struct trees {
	int x, y, life;
};
int dx[8]{ -1, 1, 0, 0, -1, 1, 1, -1 };
int dy[8]{ 0, 0, -1, 1, -1, -1, 1, 1 };
int main(void) {

	cin >> N >> M >> K;
	int x, y, life;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			energy[i][j] = 5;
			cin >> plus_energy[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> life;
		x--; y--;
		board[y][x].push_back(life);
	}
	queue<trees> q;
	trees tmp;
	int nx, ny;
	while (K--) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!board[i][j].empty()) {
					sort(board[i][j].begin(), board[i][j].end());
					for (int k = 0; k < board[i][j].size(); k++) {
						int value = board[i][j][k];
						if (value <= energy[i][j]) {
							energy[i][j] -= value;
							board[i][j][k] += 1;
						}
						else {
							q.push({ j, i, value });
							board[i][j].erase(board[i][j].begin() + k);
							k--;
						}
					}
				}
			}
		}

		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			energy[tmp.y][tmp.x] += (tmp.life / 2);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				energy[i][j] += plus_energy[i][j];
				for (int k = 0; k < board[i][j].size(); k++) {
					if (board[i][j][k] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							nx = 0; ny = 0;
							nx = j + dx[l]; ny = i + dy[l];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N)
								continue;
							board[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!board[i][j].empty()) {
				for (int k = 0; k < board[i][j].size(); k++) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << "\n";

	return 0;
}
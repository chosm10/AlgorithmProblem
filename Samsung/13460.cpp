#include<iostream>
#include<string>
#include<queue>
#define MAX 11
using namespace std;
int board[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, M;
struct ball {
	int x, y;
};
int main(void) {
	cin >> N >> M;
	string tmp;
	ball r, b;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			switch (tmp[j]) {
			case '#':
				board[i][j] = -1;
				break;
			case '.':
				board[i][j] = 0;
				break;
			case 'R':
				board[i][j] = 0;
				r = { j, i };
				break;
			case 'B':
				board[i][j] = 0;
				b = { j, i };
				break;
			case 'O':
				board[i][j] = 3;
				break;
			}
		}
	}

	queue<pair<ball, ball>> q;
	q.push(make_pair(r, b));
	ball redB, blueB, nRedB, nBlueB;
	int nrX, nrY, nbX, nbY;
	int cnt = 0;
	int qsize;
	while (!q.empty()) {
		qsize = q.size();
		cnt++;
		if (cnt > 10) {
			cout << -1 << "\n";
			return 0;
		}
		for (int k = 0; k < qsize; k++) {
			redB = q.front().first; blueB = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				nrX = redB.x; nrY = redB.y;
				nbX = blueB.x; nbY = blueB.y;
				while (true) {
					nrX += dx[i]; nrY += dy[i];
					if (board[nrY][nrX] != 0) {
						nrX -= dx[i]; nrY -= dy[i];
						break;
					}
				}
				while (true) {
					nbX += dx[i]; nbY += dy[i];
					if (board[nbY][nbX] != 0) {
						nbX -= dx[i]; nbY -= dy[i];
						break;
					}
				}
				if (board[nbY + dy[i]][nbX + dx[i]] == 3) {
					continue;
				}
				if (board[nrY + dy[i]][nrX + dx[i]] == 3) {
					cout << cnt << "\n";
					return 0;
				}
				if (nrX == nbX && nrY == nbY) {
					if (dx[i] != 0) {
						if (redB.x * dx[i] < blueB.x * dx[i]) {
							nrX -= dx[i];
						}
						else {
							nbX -= dx[i];
						}
					}
					else {
						if (redB.y * dy[i] < blueB.y * dy[i]) {
							nrY -= dy[i];
						}
						else {
							nbY -= dy[i];
						}
					}
				}

				nRedB = { nrX, nrY };
				nBlueB = { nbX, nbY };
				q.push(make_pair(nRedB, nBlueB));
			}
		}
	}

	return 0;
}
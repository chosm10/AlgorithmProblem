#include<iostream>
#include<queue>
#define MAX 102
#define LIMITT 10001
using namespace std;
int dx[4]{ 1, -1, 0, 0 };
int dy[4]{ 0, 0 ,1, -1 };
int dR[4]{ 2, 3, 1, 0 };
int dL[4]{ 3, 2, 0, 1 };
int N, K, L;
int board[MAX][MAX];
char direct[LIMITT];
int main(void) {

	cin >> N >> K;
	int x, y;
	for (int i = 0; i < N + 2; i++) {
		direct[i] = 0;
		for (int j = 0; j < N + 2; j++) {
			board[i][j] = -1; // 벽
		}
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			board[i][j] = 0; //땅
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		board[y][x] = 2; // 사과
	}
	cin >> L;
	int s;
	char d;
	for (int i = 0; i < L; i++) {
		cin >> s >> d;
		direct[s] = d;
	}
	board[1][1] = -1;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	pair<pair<int, int>, pair<int, int>> snake;
	q.push(make_pair(make_pair(1, 1), make_pair(0, 0)));//머리
	q.push(make_pair(make_pair(1, 1), make_pair(0, 0)));//꼬리
	int qsize, nx, ny, nd, sec, cnt = 0;
	while (!q.empty()) {
		qsize = q.size();
		cnt++;
		for (int i = 0; i < qsize; i++) {
			snake = q.front();
			q.pop();
			x = snake.first.first; y = snake.first.second;
			d = snake.second.first; sec = snake.second.second;
			nx = x + dx[d]; ny = y + dy[d];
			sec++;
			if (direct[sec] != 0) {
				switch (direct[sec]) {
				case 'L':
					nd = dL[d];
					break;
				case 'D':
					nd = dR[d];
					break;
				}
			}
			else {
				nd = d;
			}

			if (i == 0) { //머리면
				if (board[ny][nx] == -1) {
					cout << cnt << "\n";
					return 0;
				}
				if (board[ny][nx] == 2) {
					board[ny][nx] = -1;
					snake = q.front();
					q.pop();
					q.push(make_pair(make_pair(nx, ny), make_pair(nd, sec)));
					q.push(snake);
					break;
				}
				board[ny][nx] = -1;
			}
			else {
				board[y][x] = 0;
			}
			q.push(make_pair(make_pair(nx, ny), make_pair(nd, sec)));
		}
	}
	return 0;
}


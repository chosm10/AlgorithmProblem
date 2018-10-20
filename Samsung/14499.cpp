#include<iostream>
#define MAX 21
using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int dice[7];
int main(void) {

	int N, M, x, y, K;
	cin >> N >> M >> y >> x >> K;
	int map[MAX][MAX];
	int opr[1001];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> opr[i];
		opr[i] -= 1;
	}
	int nx, ny, nopr, tmp;
	for (int i = 0; i < K; i++) {
		nopr = opr[i];
		nx = x + dx[nopr]; ny = y + dy[nopr];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}
		tmp = dice[1];
		switch (nopr) {
		case 0:
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
			break;
		case 1:
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
			break;
		case 2:
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
			break;
		case 3:
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;
			break;
		}

		if (map[ny][nx] == 0) {
			map[ny][nx] = dice[6];
		}
		else {
			dice[6] = map[ny][nx];
			map[ny][nx] = 0;
		}
		x = nx; y = ny;
		cout << dice[1] << "\n";
	}


	return 0;
}
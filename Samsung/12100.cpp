#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N;
int copyArr[21][21];
void play(int m[21][21], int d) {
	int nx, ny, tmp;
	vector<vector<bool>> check(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}

	switch (d) {
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (m[i][j] != 0) {
					nx = j; ny = i;
					while (true) {
						nx += dx[d]; ny += dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
							break;
						}
						if (m[ny][nx] != 0) {
							tmp = m[i][j];
							m[i][j] = 0;
							if (m[ny][nx] == tmp) {
								if (!check[ny][nx]) {
									check[ny][nx] = true;
									m[ny][nx] *= 2;
								}
							}
							else {
								m[ny - dy[d]][nx - dx[d]] = tmp;
							}
							break;
						}
					}
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = N - 2; j >= 0; j--) {
				if (m[i][j] != 0) {
					nx = j; ny = i;
					while (true) {
						nx += dx[d]; ny += dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
							break;
						}
						if (m[ny][nx] != 0) {
							tmp = m[i][j];
							m[i][j] = 0;
							if (m[ny][nx] == tmp) {
								if (!check[ny][nx]) {
									check[ny][nx] = true;
									m[ny][nx] *= 2;
								}
							}
							else {
								m[ny - dy[d]][nx - dx[d]] = tmp;
							}
							break;
						}
					}
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (m[j][i] != 0) {
					nx = i; ny = j;
					while (true) {
						nx += dx[d]; ny += dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
							break;
						}
						if (m[ny][nx] != 0) {
							tmp = m[j][i];
							m[j][i] = 0;
							if (m[ny][nx] == tmp) {
								if (!check[ny][nx]) {
									check[ny][nx] = true;
									m[ny][nx] *= 2;
								}
							}
							else {
								m[ny - dy[d]][nx - dx[d]] = tmp;
							}
							break;
						}
					}
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < N; i++) {
			for (int j = N - 2; j >= 0; j--) {
				if (m[j][i] != 0) {
					nx = i; ny = j;
					while (true) {
						nx += dx[d]; ny += dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
							break;
						}
						if (m[ny][nx] != 0) {
							tmp = m[j][i];
							m[j][i] = 0;
							if (m[ny][nx] == tmp) {
								if (!check[ny][nx]) {
									check[ny][nx] = true;
									m[ny][nx] *= 2;
								}
							}
							else {
								m[ny - dy[d]][nx - dx[d]] = tmp;
							}
							break;
						}
					}
				}
			}
		}
		break;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copyArr[i][j] = m[i][j];
		}
	}
	cout << "------------\n";
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			cout << m[j][k] << " ";
		}
		cout << "\n";
	}
}
int search(int m[21][21]) {
	int result = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (result < m[i][j]) {
				result = m[i][j];
			}
		}
	}
	return result;
}
int main(void) {
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	queue<vector<vector<int>>> q;
	q.push(board);
	int qsize;
	int cnt = 0;
	int max = -1;
	int ans;



	vector<vector<int>> temp(N, vector<int>(N));
	vector<vector<int>> ntemp(N, vector<int>(N));
	int copyTemp[21][21];
	while (!q.empty()) {
		qsize = q.size();
		if (cnt == 5) {
			break;
		}
		for (int i = 0; i < qsize; i++) {

			temp = q.front();
			q.pop();
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					copyTemp[k][l] = temp[k][l];
				}
			}
			ans = search(copyTemp);
			if (max < ans) {
				max = ans;
			}

			for (int j = 0; j < 4; j++) {

				play(copyTemp, j);
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						ntemp[k][l] = copyArr[k][l];
					}
				}

				q.push(ntemp);
			}
		}
		cnt++;
	}
	cout << max << "\n";
	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#define MAX 4004
using namespace std;
int N;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int board[MAX][MAX];
int time_limit;
struct atom {
	int x, y, d, k;
}v[101];
bool check[101];

int q[101];
int main(int argc, char** argv)
{
	int test_case, T;
	cin >> T;

	int x, y;
	int d, k;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < 101; i++) {
			check[i] = true;
			v[i] = { 0,0,0,0 };
			q[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> d >> k;
			v[i] = { (x + 1000) * 2, (y + 1000) * 2, d, k };
		}
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				board[i][j] = 0;
			}
		}
		time_limit = 4004;
		int sum = 0;
		int count = N;
		while (time_limit--) {
			if (count == 0)
				break;
			for (int i = 0; i < N; i++) {
				if (!check[i])
					continue;
				x = v[i].x; y = v[i].y;
				x += dx[v[i].d]; y += dy[v[i].d];
				if (x < 0 || x >= 4001 || y < 0 || y >= 4001) {
					count--;
					check[i] = false;
					board[v[i].y][v[i].x] -= 1;
					continue;
				}
				board[y][x] += 1;
				board[v[i].y][v[i].x] -= 1;
				v[i].x = x; v[i].y = y;
			}
			int index = 0;
			for (int i = 0; i < N; i++) {
				if (!check[i])
					continue;
				if (board[v[i].y][v[i].x] >= 2) {
					count--;
					sum += v[i].k;
					q[index++] = i;
					check[i] = false;
				}
			}
			for (int i = 0; i < index; i++) {
				board[v[q[i]].y][v[q[i]].x] = 0;
			}
		}
		cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;
}
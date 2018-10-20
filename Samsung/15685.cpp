#include<iostream>
#include<vector>
using namespace std;
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, -1, 0, 1 };
int nd[4]{ 3, 0, 1, 2 };
int board[101][101];
int main(void) {

	int N;
	cin >> N;

	vector<vector<pair<int, int>>> curb(N);
	vector<int> generation;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		int nx = x + dx[d], ny = y + dy[d];
		curb[i].push_back(make_pair(x, y));
		curb[i].push_back(make_pair(nx, ny));
		generation.push_back(g);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < generation[i]; j++) {
			int size = curb[i].size();
			for (int j = size - 1; j > 0; j--) {
				int direction = 0;
				int ddx = curb[i][j - 1].first - curb[i][j].first;
				int ddy = curb[i][j - 1].second - curb[i][j].second;
				if (ddx == 0) {
					if (ddy == -1) {
						direction = 1;
					}
					else {
						direction = 3;
					}
				}
				else {
					if (ddx == 1) {
						direction = 0;
					}
					else {
						direction = 2;
					}
				}
				direction = nd[direction];
				int nnx = curb[i][curb[i].size() - 1].first + dx[direction];
				int nny = curb[i][curb[i].size() - 1].second + dy[direction];
				curb[i].push_back(make_pair(nnx, nny));
			}
		}
	}
	for (int i = 0; i < curb.size(); i++) {
		for (int j = 0; j < curb[i].size(); j++) {
			if (curb[i][j].first >= 0 && curb[i][j].second >= 0) {
				board[curb[i][j].second][curb[i][j].first] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
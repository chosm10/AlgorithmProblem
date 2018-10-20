#include<iostream>
#include<vector>
#define MAX 8
#define INF 987654321
using namespace std;
bool check[8][8];
int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };
int l[4]{ 2, 1, 3, 0 };
vector<pair<pair<int, int>, int>> cc;
int map[MAX][MAX];
int N, M;
int totalArea = INF;
void cc1(int x, int y, int d, int change) {
	while (true) {
		x += dx[d];
		y += dy[d];
		if (map[y][x] == 6) {
			break;
		}
		if (x < 0 || x >= M || y < 0 || y >= N) {
			return;
		}
		if (map[y][x] <= 0) {
			if (change == -1)
				map[y][x] -= 1;
			else
				map[y][x] += 1;
		}
	}
}
void cc2(int x, int y, int d, int change) {
	cc1(x, y, l[d], change);
	cc1(x, y, l[d + 2], change);
}
void cc3(int x, int y, int d, int change) {
	cc1(x, y, l[d], change);
	cc1(x, y, l[(d + 1) % 4], change);
}
void cc4(int x, int y, int d, int change) {
	cc1(x, y, l[d], change);
	cc1(x, y, l[(d + 1) % 4], change);
	cc1(x, y, l[(d + 2) % 4], change);
}
void cc5(int x, int y, int change) {
	cc1(x, y, 0, change);
	cc1(x, y, 1, change);
	cc1(x, y, 2, change);
	cc1(x, y, 3, change);
}
int search() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}
void dfs(int index) {
	int ans;
	int size = cc.size();
	switch (cc[index].second) {
	case 1:
		for (int i = 0; i < 4; i++) {
			cc1(cc[index].first.first, cc[index].first.second, i, -1);
			if (index + 1 < size) {
				dfs(index + 1);
			}
			else {
				ans = search();
				if (totalArea > ans) {
					totalArea = ans;
				}
			}
			cc1(cc[index].first.first, cc[index].first.second, i, 0);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			cc2(cc[index].first.first, cc[index].first.second, i, -1);
			if (index + 1 < size) {
				dfs(index + 1);
			}
			else {
				ans = search();
				if (totalArea > ans) {
					totalArea = ans;
				}
			}
			cc2(cc[index].first.first, cc[index].first.second, i, 0);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			cc3(cc[index].first.first, cc[index].first.second, i, -1);
			if (index + 1 < size) {
				dfs(index + 1);
			}
			else {
				ans = search();
				if (totalArea > ans) {
					totalArea = ans;
				}
			}
			cc3(cc[index].first.first, cc[index].first.second, i, 0);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			cc4(cc[index].first.first, cc[index].first.second, i, -1);
			if (index + 1 < size) {
				dfs(index + 1);
			}
			else {
				ans = search();
				if (totalArea > ans) {
					totalArea = ans;
				}
			}
			cc4(cc[index].first.first, cc[index].first.second, i, 0);
		}
		break;
	case 5:
		cc5(cc[index].first.first, cc[index].first.second, -1);
		if (index + 1 < size) {
			dfs(index + 1);
		}
		else {
			ans = search();
			if (totalArea > ans) {
				totalArea = ans;
			}
		}
		cc5(cc[index].first.first, cc[index].first.second, 0);
	}
}
int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cc.push_back(make_pair(make_pair(j, i), map[i][j]));
			}
		}
	}
	if (!cc.empty()) {
		dfs(0);
	}
	else {
		totalArea = search();
	}
	cout << totalArea << "\n";

	return 0;
}
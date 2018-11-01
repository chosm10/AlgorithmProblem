#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#define MAX 22
using namespace std;
int N;
int board[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
struct fish {
	int x, y, big, eat;
};
fish me;
int cnt = 0;
bool bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}
	check[me.y][me.x] = true;
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(0, make_pair(me.x, me.y)));
	vector<pair<int, pair<int, int> > > fishs; // dist, y, x
	pair<int, pair<int, int> >p;
	while (!q.empty()) {

		p = q.front();
		q.pop();

		if (board[p.second.second][p.second.first] != 0 && board[p.second.second][p.second.first] < me.big) {
			fishs.push_back(make_pair(p.first, make_pair(p.second.second, p.second.first)));
		}

		for (int i = 0; i < 4; i++) {
			int nx = p.second.first + dx[i];
			int ny = p.second.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[ny][nx] <= me.big) {
				if (!check[ny][nx]) {
					check[ny][nx] = true;
					q.push(make_pair(p.first + 1, make_pair(nx, ny)));
				}
			}
		}
	}
	if (fishs.empty())
		return false;
	sort(fishs.begin(), fishs.end());
	cnt += fishs[0].first;
	me.eat += 1;
	if (me.big == me.eat) {
		me.eat = 0;
		me.big += 1;
	}
	me.x = fishs[0].second.second;
	me.y = fishs[0].second.first;
	board[me.y][me.x] = 0;
	return true;
}
int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				me.x = j; me.y = i;
				me.big = 2; me.eat = 0;
				board[i][j] = 0;
			}
		}
	}
	bool exist;
	while (true) {
		exist = bfs();
		if (!exist)
			break;
	}
	cout << cnt << "\n";

	return 0;
}
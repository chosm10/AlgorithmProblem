#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int N, M, H;
int map[31][11];
bool play(int start) {
	int current = start;
	for (int i = 1; i <= H; i++) {
		if (map[i][current] != 0) {
			if (map[i][current] == map[i][current + 1]) {
				current += 1;
			}
			else if (map[i][current] == map[i][current - 1]) {
				current -= 1;
			}
		}
	}
	if (current == start) {
		return true;
	}
	return false;
}
bool possible() {
	for (int i = 1; i <= N; i++) {
		if (!play(i)) {
			return false;
		}
	}
	return true;
}
int main(void) {
	cin >> N >> M >> H;
	int a, b;
	int cnt = 1;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = cnt;
		map[a][b + 1] = cnt;
		cnt++;
	}
	int limitM = H * (N - 1);
	vector<vector<int>> combination(3);
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < i; j++) {
			combination[i - 1].push_back(0);
		}
		for (int j = 0; j < limitM - i; j++) {
			combination[i - 1].push_back(1);
		}
	}

	if (possible()) {
		cout << "0\n";
		return 0;
	}
	int x, y;
	stack<pair<int, int>> s;
	bool skip = true;
	for (int i = 0; i < 3; i++) {
		do {
			skip = true;
			for (int j = 0; j < combination[i].size(); j++) {
				if (combination[i][j] == 0) {
					x = j % (N - 1) + 1;
					y = j / (N - 1) + 1;
					if (map[y][x] != 0 || map[y][x + 1] != 0) {
						skip = false;
						break;
					}
					map[y][x] = cnt;
					map[y][x + 1] = cnt;
					s.push(make_pair(x, y));
					s.push(make_pair(x + 1, y));
					cnt++;
				}
			}
			if (skip && possible()) {
				cout << i + 1 << "\n";
				return 0;
			}

			while (!s.empty()) {
				map[s.top().second][s.top().first] = 0;
				s.pop();
			}
		} while (next_permutation(combination[i].begin(), combination[i].end()));
	}
	cout << -1 << "\n";
	return 0;
}
#include<iostream>
#include<map>
#include<queue>
using namespace std;
int N;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int time_limit;
struct atom {
	int x, y, d, k;
};
int main(int argc, char** argv)
{
	int test_case, T;
	cin >> T;
	queue<atom> q;
	pair<int, int> p;
	map<pair<int, int>, pair<int, int>> m_copy;
	map<pair<int, int>, pair<int, int>> ::iterator iter;
	int x, y;
	int d, k;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		m_copy.clear();
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> d >> k;
			q.push({ x * 2, y * 2, d, k });
		}
		time_limit = 4004;
		int sum = 0;
		atom tmp;
		while (time_limit--) {
			while (!q.empty()) {
				tmp = q.front();
				q.pop();
				x = tmp.x; y = tmp.y; d = tmp.d; k = tmp.k;
				x += dx[d]; y += dy[d];
				p = make_pair(x, y);
				if (m_copy.find(p) == m_copy.end()) {
					m_copy[p] = { d, k };
				}
				else {
					if (m_copy[p].second > 0) {
						m_copy[p].second = -m_copy[p].second - k;
					}
					else {
						m_copy[p].second -= k;
					}
				}
			}
			for (iter = m_copy.begin(); iter != m_copy.end(); iter++) {
				x = iter->first.first; y = iter->first.second; d = iter->second.first; k = iter->second.second;
				if (k < 0) {
					sum -= k;
				}
				else {
					q.push({ x, y, d, k });
				}
			}
			m_copy.clear();
		}

		cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;
}
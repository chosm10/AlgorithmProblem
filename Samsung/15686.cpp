#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main(void) {

	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N);
	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			v[i].push_back(n);
			if (n == 1) {
				house.push_back(make_pair(j, i));
			}
			else if (n == 2) {
				chicken.push_back(make_pair(j, i));
			}
		}
	}
	int comSize = chicken.size();
	vector<int> com;
	for (int i = 0; i < M; i++) {
		com.push_back(0);
	}
	for (int i = 0; i < comSize - M; i++) {
		com.push_back(1);
	}
	int min = 50 * 50;
	do {
		vector<pair<int, int>> select;
		for (int i = 0; i < com.size(); i++) {
			if (com[i] == 0) {
				select.push_back(chicken[i]);
			}
		}
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int cdist = N * 2 + 1;
			for (int j = 0; j < select.size(); j++) {
				int distAB = dist(house[i], select[j]);
				if (cdist > distAB) {
					cdist = distAB;
				}
			}
			sum += cdist;
		}
		if (min > sum) {
			min = sum;
		}
	} while (next_permutation(com.begin(), com.end()));

	cout << min << "\n";
	return 0;
}
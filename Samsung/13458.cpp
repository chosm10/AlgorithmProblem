#include<iostream>
#include<vector>
using namespace std;

int main(void) {

	int N, B, C;
	cin >> N;
	vector<int> room;
	int ai;
	for (int i = 0; i < N; i++) {
		cin >> ai;
		room.push_back(ai);
	}
	cin >> B >> C;

	long long result = N;
	for (int i = 0; i < N; i++) {
		room[i] -= B;
		if (room[i] > 0) {
			result += room[i] / C;
			if (room[i] % C != 0) {
				result += 1;
			}
		}
	}
	cout << result << "\n";
	return 0;
}
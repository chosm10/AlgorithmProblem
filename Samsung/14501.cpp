#include<iostream>
using namespace std;
int T[16];
int P[16];
int maxProfit[16];
int main(void) {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		maxProfit[i] = P[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (j + T[j] <= i) {
				maxProfit[i] = (maxProfit[i] > maxProfit[j] + P[i]) ? maxProfit[i] : maxProfit[j] + P[i];
			}
		}
	}
	int maxP = 0;
	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			if (maxP < maxProfit[i]) {
				maxP = maxProfit[i];
			}
		}
	}

	cout << maxP << "\n";
	return 0;
}
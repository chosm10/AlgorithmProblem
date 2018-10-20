#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;
int N;
struct atom {
	double x, y;
	int d, k;
};
double can_meet(atom a, atom b) {

	if (a.x == b.x) {
		if (a.y > b.y) {
			if (a.d == 1 && b.d == 0) {
				return (a.y - b.y) / 2;
			}
		}
		else {
			if (a.d == 0 && b.d == 1) {
				return (b.y - a.y) / 2;
			}
		}
	}
	else if (a.y == b.y) {
		if (a.x > b.x) {
			if (a.d == 2 && b.d == 3) {
				return (a.x - b.x) / 2;
			}
		}
		else {
			if (a.d == 3 && b.d == 2) {
				return (b.x - a.x) / 2;
			}
		}
	}

	if (abs(a.x - b.x) == abs(a.y - b.y)) {
		if (a.x > b.x) {
			if (a.y > b.y) {
				if ((a.d == 1 && b.d == 3) || (a.d == 2 && b.d == 0)) {
					return (a.x - b.x);
				}
			}
			else {
				if ((a.d == 0 && b.d == 3) || (a.d == 2 && b.d == 1)) {
					return (a.x - b.x);
				}
			}
		}
		else {
			if (a.y > b.y) {
				if ((a.d == 3 && b.d == 0) || (a.d == 1 && b.d == 2)) {
					return (b.x - a.x);
				}
			}
			else {
				if ((a.d == 3 && b.d == 1) || (a.d == 0 || b.d == 2)) {
					return (b.x - a.x);
				}
			}
		}
	}

	return 2004;
}
struct cmp {
	bool operator() (atom a, atom b) {
		return (a.x*a.x + a.y*a.y) > (b.x*b.x + b.y*b.y);
	}
};
int main(void) {

	int test_case, T;
	cin >> T;
	priority_queue<atom, vector<atom>, cmp> q;
	queue<atom> tmp_q;
	double x, y;
	int d, k;
	atom tmp1;
	atom tmp2;
	int qsize = 0;
	stack<atom> s;
	double sec;
	long long sum;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x >> y >> d >> k;
			tmp1 = { x, y, d, k };
			q.push(tmp1);
		}
		sum = 0;

		while (!q.empty()) {
			tmp1 = q.top();
			q.pop();
			qsize = q.size();
			sec = 2001;
			for (int i = 0; i < qsize; i++) {
				tmp2 = q.top();
				q.pop();
				if (sec > can_meet(tmp1, tmp2)) {
					sec = can_meet(tmp1, tmp2);
					while (!s.empty()) {
						tmp_q.push(s.top());
						s.pop();
					}
					s.push(tmp2);
				}
				else if (sec == can_meet(tmp1, tmp2)) {
					s.push(tmp2);
				}
				else {
					tmp_q.push(tmp2);
				}
			}
			if (!s.empty()) {
				sum += tmp1.k;
			}
			while (!s.empty()) {
				sum += s.top().k;
				s.pop();
			}
			while (!tmp_q.empty()) {
				q.push(tmp_q.front());
				tmp_q.pop();
			}
		}

		cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;
}
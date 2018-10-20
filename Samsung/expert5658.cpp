#include<iostream>
#include<string>
#include<map>
using namespace std;
int hex_str_to_dec(string s) {
	int expr = 1, result = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] <= '9') {
			result += (s[i] - '0') * expr;
		}
		else {
			result += (s[i] - 'A' + 10) * expr;
		}
		expr *= 16;
	}
	return result;
}
int main(void) {

	int T, N, K;
	string numbers;
	map<string, string> maps;
	map<string, string>::iterator iter;

	int num_size;
	int cnt = 0;
	int nt = 0;
	string key_string;
	string key_number;
	cin >> T;
	while (T--) {
		nt++;
		maps.clear();
		cin >> N >> K;
		cin >> numbers;
		num_size = N / 4;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				key_number = numbers.substr(j*num_size, num_size);
				if (maps.find(key_number) == maps.end()) {
					maps[key_number] = key_number;
				}
			}
			numbers = numbers.substr(1, N - 1) + numbers[0];
		}
		cnt = 0;
		for (iter = --maps.end(); iter != maps.begin(); iter--) {
			cnt++;
			if (cnt == K) {
				break;
			}
		}
		key_string = iter->second;
		cout << "#" << nt << " " << hex_str_to_dec(key_string);
	}
	return 0;
}

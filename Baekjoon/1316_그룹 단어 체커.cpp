#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int result = 0;

void check_word(string str) {

	stack<string> s;
	unordered_map<string, int> um;

	for (int i = 0; i < str.size(); i++) {
		string next = str.substr(i, 1);

		if (!s.empty()) {
			if (s.top() != next) s.push(next);
		}
		else s.push(next);
	}

	if (!s.empty()) {

		while (!s.empty()) {
			um[s.top()]++;
			s.pop();
		}

		for (pair<string, int> tmp : um) {
			if (tmp.second > 1) return;
		}
	}

	result++;
	return;
}

int main() {
	int num;
	cin >> num;

	while (num--) {
		string str;
		cin >> str;
		check_word(str);
	}

	cout << result;
}
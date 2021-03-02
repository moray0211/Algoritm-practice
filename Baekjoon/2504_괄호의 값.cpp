#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	int result = 0;

	stack<int> s;
	stack<int> tmp_s;

	for (int i = 0; i < str.length(); i++) {
		string tmp = str.substr(i, 1);

		if (tmp != "(" && tmp != ")" && tmp != "[" && tmp != "]") {
			cout << 0;
			return 0;
		}

		if (tmp == "(") s.push(-2);
		if (tmp == "[") s.push(-3);
		if (tmp == ")") {
			if (s.empty() || s.top() == -3) { cout << 0; return 0; }
			int num = s.top();
			if (num == -2) {
				s.pop();
				s.push(2);
			}
			else {
				//(�� ã�� �� ����
				while (num != -2) {
					if (num == -3 || s.empty()) {
						cout << 0;
						return 0;
					}
					tmp_s.push(num * 2);
					s.pop();
					if (s.empty()) { cout << 0; return 0; }
					num = s.top();
				}
				//ã�Ҵٸ�
				s.pop();
				int tmp_num = 0;
				while (!tmp_s.empty()) {
					tmp_num += tmp_s.top();
					tmp_s.pop();
				}
				s.push(tmp_num);
			}
		}
		if (tmp == "]") {
			if (s.empty() || s.top() == -2) { cout << 0; return 0; }
			int num = s.top();
			if (num == -3) {
				if (num == -2 || s.empty()) {
					cout << 0;
					return 0;
				}
				s.pop();
				s.push(3);
			}
			else {
				//[�� ã�� �� ����
				while (num != -3) {
					tmp_s.push(num * 3);
					s.pop();
					if (s.empty()) { cout << 0; return 0; }
					num = s.top();
				}
				//ã�Ҵٸ�
				s.pop();
				int tmp_num = 0;
				while (!tmp_s.empty()) {
					tmp_num += tmp_s.top();
					tmp_s.pop();
				}
				s.push(tmp_num);
			}
		}

	}

	while (!s.empty()) {
		if (s.top() == -2 || s.top() == -3) {
			cout << 0;
			return 0;
		}
		result += s.top();
		s.pop();
	}
	cout << result;

}
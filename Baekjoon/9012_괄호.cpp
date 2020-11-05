#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int T;
vector<string> result;

int main() {

	cin >> T;

	while (T--) {
		string str;
		stack<string> s;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			string tmp = str.substr(i, 1);
			if (s.empty()) s.push(tmp);
			else {
				if (s.top() == "(" && tmp == ")") s.pop();
				else s.push(tmp);
			}
		}

		if (s.empty()) result.push_back("YES");
		else result.push_back("NO");
	}

	for (int i = 0; i < result.size(); i++) { cout << result[i] << endl; }
}
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	//해시값 입력
	unordered_map<char, int> um;
	int n = 0;
	for (int i = 2; i <= 9; i++) {
		for (int j = 0; j < 4; j++) {
			char ch = 'A' + n++;
			um[ch] = i + 1;

			if (j == 2 && !(i == 7 || i == 9)) break;

		}
	}

	string str;
	cin >> str;

	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		string tmp = str.substr(i, 1);
		result += um[tmp.at(0)];
	}

	cout << result;

}
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	unordered_map<string, int> order; //<key, value>
	string a = words[0].substr(0, 1);

	for (int i = 0; i<words.size(); i++) {

		if (order[words[i]] != 0) {
			answer.push_back(i%n + 1);
			answer.push_back(i / n + 1);
			break;
		}
		else {
			string b = words[i].substr(0, 1);
			if (a != b) {
				answer.push_back(i%n + 1);
				answer.push_back(i / n + 1);
				break;
			}
			order[words[i]] = i + 1;
			a = words[i].substr(words[i].length() - 1);
		}
	}

	if (answer.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> tmp;

	int i, j, k;
	for (int p = 0; p<commands.size(); p++) {
		i = commands[p][0];
		j = commands[p][1];
		k = commands[p][2];
		//i번째부터 j번째까지 자르고 정렬해서 k번째 수 구하기.
		for (int t = i - 1; t <= j - 1; t++) {
			tmp.push_back(array[t]);
		}
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[k - 1]);
		tmp.clear();
	}

	return answer;
}
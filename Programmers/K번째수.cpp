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
		//i��°���� j��°���� �ڸ��� �����ؼ� k��° �� ���ϱ�.
		for (int t = i - 1; t <= j - 1; t++) {
			tmp.push_back(array[t]);
		}
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[k - 1]);
		tmp.clear();
	}

	return answer;
}
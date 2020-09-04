#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int person[3][10]
		= { { 1,2,3,4,5 },{ 2,1,2,3,2,4,2,5 },{ 3,3,1,1,2,2,4,4,5,5 } };
	vector<int> tmp(3, 0);

	for (int i = 0; i<answers.size(); i++) {

		if (person[0][i % 5] == answers[i]) tmp[0]++;
		if (person[1][i % 8] == answers[i]) tmp[1]++;
		if (person[2][i % 10] == answers[i]) tmp[2]++;

	}

	int max_num = 0;
	for (int i = 0; i<3; i++) {
		max_num = (max_num <= tmp[i]) ? tmp[i] : max_num;
	}
	for (int i = 0; i<3; i++) {
		if (max_num == tmp[i]) answer.push_back(i + 1);
	}

	return answer;
}
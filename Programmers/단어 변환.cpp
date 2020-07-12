#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> visit;
vector<int> result;
int length; //�ܾ��� ����
bool isFirst = true;

void DFS(string begin, string target, vector<string> words, vector<bool> visit, int num, int n) {

	string str;
	if (!isFirst) {
		visit[num] = true;
		str = words[num];
	}
	else {
		isFirst = false; //ù��° DFS �ƴ�.
		str = begin;
	}

	if (str.compare(target) == 0) result.push_back(n);

	for (int i = 0; i<words.size(); i++) {
		int tmp = 0;
		for (int j = 0; j<length; j++) { //i��° �ܾ��� ���ĺ� j���� �˻�
										 //�� ���� �� ���� ���ĺ��� �ٲ� �� ����
			if (words[i].at(j) == str.at(j) && !visit[i]) tmp++;
		}
		if (tmp == length - 1) DFS(begin, target, words, visit, i, n + 1);
	}
}

int check_min() {
	if (result.size() == 0) return 0;
	sort(result.begin(), result.end());
	return result[0];
}

//begin���� target���� �ּ� �Ÿ�. �ܾ�� words�θ� ��ȯ����. �ѹ��� ���ĺ� �Ѱ���.
//�ܾ� ���� ����
int solution(string begin, string target, vector<string> words) {
	visit.assign(words.size(), false);
	length = begin.size();

	DFS(begin, target, words, visit, 0, 0);
	int answer = check_min();
	return answer;
}
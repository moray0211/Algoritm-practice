#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> visit;
vector<int> result;
int length; //단어의 길이
bool isFirst = true;

void DFS(string begin, string target, vector<string> words, vector<bool> visit, int num, int n) {

	string str;
	if (!isFirst) {
		visit[num] = true;
		str = words[num];
	}
	else {
		isFirst = false; //첫번째 DFS 아님.
		str = begin;
	}

	if (str.compare(target) == 0) result.push_back(n);

	for (int i = 0; i<words.size(); i++) {
		int tmp = 0;
		for (int j = 0; j<length; j++) { //i번째 단어의 알파벳 j개를 검사
										 //한 번에 한 개의 알파벳만 바꿀 수 있음
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

//begin부터 target으로 최소 거리. 단어는 words로만 변환가능. 한번에 알파벳 한개만.
//단어 길이 같음
int solution(string begin, string target, vector<string> words) {
	visit.assign(words.size(), false);
	length = begin.size();

	DFS(begin, target, words, visit, 0, 0);
	int answer = check_min();
	return answer;
}
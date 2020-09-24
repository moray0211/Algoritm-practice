#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int N; //문제의 수
int M; //먼저 푸는 것이 좋은 문제에 대한 정보의 개수

	   /* !!문제 조건 유의!! */

vector<vector<int>> pre_pro; //먼저 풀어야 하는 문제들
vector<vector<int>> next_pro; //이 문제를 품으로써 풀 수 있는 문제들

int main() {
	cin >> N >> M;

	pre_pro.resize(N + 2); //N개의 문제
	next_pro.resize(N + 2);

	priority_queue<int, vector<int>, greater<int>> single_pro; //먼저 풀면 좋은 문제가 전부 풀린 문제들
	vector<bool> used(32002, false);

	for (int i = 0; i < M; i++) {
		//먼저 풀면 좋은 문제가 여러개 있을 수 있다.
		//같은 먼저 풀면 좋은 문제가 여러개 있을 수 있다. (그 역도 여러개 있을 수 있다)
		int a, b; //a번 문제는 b번 문제보다 먼저 풀어야한다
		cin >> a >> b;
		next_pro[a].push_back(b); //next_pro[번호] 에는 (번호 번 문제가 먼저 풀어야 하는 문제로 지정되었던 문제) 가 들어가 있다.
		pre_pro[b].push_back(a); //pre_pro[번호] 에는 (먼저 풀어야 하는 문제) 가 들어가 있다.
	}

	//먼저 푸는 것이 좋은 문제가 있을 경우, 무조건 그 문제를 먼저 풀어야 하지만
	//그 문제를 풀고 나서, 쌍으로 주어진 원래 문제는 나중에 풀어도 된다

	//바로 풀 수 있는 문제들 저장
	for (int i = 1; i <= N; i++) {
		if (pre_pro[i].empty()) single_pro.push(i);
	}

	while (!single_pro.empty()) {

		int tmp = single_pro.top();
		if (!used[tmp]) cout << tmp << " ";
		used[tmp] = true;
		single_pro.pop();

		for (int i = 0; i < next_pro[tmp].size(); i++) {
			bool isCorrect = true;
			for (int j = 0; j < pre_pro[next_pro[tmp][i]].size(); j++) {
				if (!used[pre_pro[next_pro[tmp][i]][j]]) {
					isCorrect = false;
					break;
				}
			}
			if (isCorrect) single_pro.push(next_pro[tmp][i]);
		}

	}

}
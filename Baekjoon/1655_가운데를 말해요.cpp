#include <vector>
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int N; //외치는 정수의 개수

int main() {
	scanf("%d", &N);

	priority_queue<int> max_pq; //최대 힙
	priority_queue<int, vector<int>, greater<int>> min_pq; //최소 힙
	vector<int> result;

	/*
	[중간값 구하는 알고리즘]
	1. 최대 힙의 사이즈는 최소 힙과 같거나 1 더 커야함
	2. 최소 힙의 Top >= 최대 힙의 Top
	3. 1,2번 규칙이 맞지 않을 경우 Swap
	*/

	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);

		//1번 조건
		if ((!max_pq.empty()) && (max_pq.size() > min_pq.size())) min_pq.push(n);
		else max_pq.push(n);

		//2번 조건 -> 3번 조건
		if ((!min_pq.empty()) && (!max_pq.empty()) && (min_pq.top() < max_pq.top())) {
			int a = min_pq.top();
			int b = max_pq.top();
			min_pq.pop();
			max_pq.pop();
			min_pq.push(b);
			max_pq.push(a);
		}

		result.push_back(max_pq.top());
	}

	for (int i = 0; i < result.size(); i++) printf("%d\n", result[i]);

}
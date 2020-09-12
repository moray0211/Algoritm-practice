#include <string>
#include <vector>
#include <functional> //greater
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	//<자료형, 구현체, 비교 연산자>
	// *구현체 : vector<자료형>
	// *비교 연산다 : 큰 것부터 less<자료형> 작은 것부터 greater<연산자>
	priority_queue <int, vector<int>, greater<int>> pq;

	for (int i = 0; i<scoville.size(); i++) { pq.push(scoville[i]); }

	while (pq.top() < K && (!pq.empty()))
	{
		int a = pq.top(); //가장 덜 매운 것
		pq.pop();
		if (pq.empty()) break;

		int b = pq.top(); //두번째로 가장 덜 매운 것
		pq.pop();

		pq.push(a + b * 2);
		answer++;
	}
	if (pq.empty()) answer = -1;

	return answer;
}
#include <string>
#include <vector>
#include <functional> //greater
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	//<�ڷ���, ����ü, �� ������>
	// *����ü : vector<�ڷ���>
	// *�� ����� : ū �ͺ��� less<�ڷ���> ���� �ͺ��� greater<������>
	priority_queue <int, vector<int>, greater<int>> pq;

	for (int i = 0; i<scoville.size(); i++) { pq.push(scoville[i]); }

	while (pq.top() < K && (!pq.empty()))
	{
		int a = pq.top(); //���� �� �ſ� ��
		pq.pop();
		if (pq.empty()) break;

		int b = pq.top(); //�ι�°�� ���� �� �ſ� ��
		pq.pop();

		pq.push(a + b * 2);
		answer++;
	}
	if (pq.empty()) answer = -1;

	return answer;
}
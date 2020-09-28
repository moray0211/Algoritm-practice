#include <vector>
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int N; //��ġ�� ������ ����

int main() {
	scanf("%d", &N);

	priority_queue<int> max_pq; //�ִ� ��
	priority_queue<int, vector<int>, greater<int>> min_pq; //�ּ� ��
	vector<int> result;

	/*
	[�߰��� ���ϴ� �˰���]
	1. �ִ� ���� ������� �ּ� ���� ���ų� 1 �� Ŀ����
	2. �ּ� ���� Top >= �ִ� ���� Top
	3. 1,2�� ��Ģ�� ���� ���� ��� Swap
	*/

	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);

		//1�� ����
		if ((!max_pq.empty()) && (max_pq.size() > min_pq.size())) min_pq.push(n);
		else max_pq.push(n);

		//2�� ���� -> 3�� ����
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
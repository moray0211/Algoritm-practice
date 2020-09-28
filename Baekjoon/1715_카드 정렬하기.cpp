#include <vector>
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int N; //N개의 카드 묶음
long long result = 0;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		long long n;
		scanf("%d", &n);
		pq.push(n);
	}

	while (!pq.empty()) {
		int a = pq.top();
		pq.pop();

		if (pq.empty()) break;

		int b = pq.top();
		pq.pop();

		result += (a + b);
		pq.push(a + b);
	}

	printf("%d", result);
}
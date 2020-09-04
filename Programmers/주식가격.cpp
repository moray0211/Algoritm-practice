#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	stack<int> stk;

	const int SIZE = prices.size();
	answer.assign(SIZE, 0);

	for (int i = 0; i<SIZE; i++) {
		while (!stk.empty()) stk.pop();
		stk.push(prices[i]);

		for (int j = i + 1; j<SIZE; j++) {
			answer[i]++;
			if (stk.top()>prices[j]) break;
		}
	}


	return answer;
}
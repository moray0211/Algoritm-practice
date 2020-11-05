#include <cstdio>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int N; //Å¾ÀÇ ¼ö
stack <pair<int, int>> s;

int main() {

	scanf("%d", &N);
	vector<int> result(N, 0);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);

		while (true) {

			if (s.empty()) {
				result[i] = 0;
				break;
			}
			else {
				if (s.top().first >= a) { result[i] = s.top().second;  break; }
				else s.pop();
			}

		}
		s.push(make_pair(a, i + 1));

	}

	for (int i = 0; i < N; i++) {
		printf("%d ", result[i]);
	}

}
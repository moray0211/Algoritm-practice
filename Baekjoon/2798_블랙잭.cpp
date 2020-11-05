#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N; //카드의 수
int M; //M을 넘지 않으면서 M에 최대한 가까운 카드 3장 고르기

int main() {
	scanf("%d %d", &N, &M);
	vector<int> card;

	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		card.push_back(n);
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int tmp = card[i] + card[j] + card[k];
				if (tmp <= M && tmp > result) result = tmp;
			}
		}
	}

	printf("%d", result);

}
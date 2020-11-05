#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N; //ī���� ��
int M; //M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3�� ����

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
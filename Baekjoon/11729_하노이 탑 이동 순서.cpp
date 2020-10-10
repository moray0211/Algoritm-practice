#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int N; //��뿡 ���� ������ ����
int num = 0;
vector <pair<int, int>> result;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		result.push_back(make_pair(from, to));
		num++;
	}
	else {
		/*
		���� ž�� 1->3->2 �� �ű� ��,
		�� ������ ĭ�� 3���� �Ű�����
		�ٽ� 2->1->3���� �Űܼ� �ϼ���Ų��.
		*/
		hanoi(n - 1, from, to, by);
		result.push_back(make_pair(from, to));
		num++;
		hanoi(n - 1, by, from, to);
	}
}

int main() {

	scanf("%d", &N);
	hanoi(N, 1, 2, 3);

	printf("%d\n", num);
	for (int i = 0; i < result.size(); i++) {
		printf("%d %d\n", result[i].first, result[i].second);
	}

}
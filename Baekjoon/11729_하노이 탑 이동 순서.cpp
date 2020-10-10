#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int N; //장대에 쌓인 원판의 갯수
int num = 0;
vector <pair<int, int>> result;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		result.push_back(make_pair(from, to));
		num++;
	}
	else {
		/*
		현재 탑을 1->3->2 로 옮긴 뒤,
		맨 마지막 칸이 3으로 옮겨지면
		다시 2->1->3으로 옮겨서 완성시킨다.
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
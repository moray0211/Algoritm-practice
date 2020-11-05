#include <cstdio>
#include <vector>
#include <cmath> //sqrt�� ���� ���� include �Ұ�

using namespace std;

const int MAX_SIZE = 1000001;
int n;
vector<bool> sosu(1000001, true);

//�����佺�׳׽��� ü
void che() {
	for (int i = 2; i < sqrt(MAX_SIZE); i++) {
		for (int j = 2; i*j < MAX_SIZE; j++) {
			if (sosu[i*j])sosu[i*j] = false;
		}
	}
}

int main() {
	che();
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;

		int i = 3;

		while (true) {

			if (n - i <= 0) {
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}

			if (i % 2 != 0 && (n - i) % 2 != 0) {
				if (sosu[i] && sosu[n - i]) {
					printf("%d = %d + %d\n", n, i, n - i);
					break;
				}
			}

			i++;
		}

	}

}
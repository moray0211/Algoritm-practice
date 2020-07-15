#include <iostream>
#include <vector>

using namespace std;

int main() {
	//N������ ����(������ ����)���� K�� �����
	//���� �ּ������� ����Ұ�.

	//Ž����̶�� �� �͵� ����, ����� �� �ִ� ���� ū ������ ���� ����ϸ� ������.

	int N, K;
	cin >> N >> K;
	int result = 0; //������ � ����ߴ���
	int now = 0; //���� �ݾ�

	vector<int> coins;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		coins.push_back(a);
	}

	for (int i = coins.size() - 1; i >= 0; i--) {
		while (true) {
			if (coins[i] <= K - now) {
				now += coins[i];
				result++;
			}
			else break;
		}
	}

	cout << result;
}
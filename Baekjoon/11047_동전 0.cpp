#include <iostream>
#include <vector>

using namespace std;

int main() {
	//N종류의 동전(갯수는 무한)으로 K원 만들기
	//동전 최소한으로 사용할것.

	//탐욕법이라고 할 것도 없이, 사용할 수 있는 가장 큰 동전을 먼저 사용하면 최적해.

	int N, K;
	cin >> N >> K;
	int result = 0; //동전을 몇개 사용했는지
	int now = 0; //현재 금액

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
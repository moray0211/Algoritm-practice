#include <iostream>
#include <vector>
using namespace std;

int T; //테스트 케이스의 갯수
int n; //정수, 0<n<11
int num = 0; //1,2,3의 합으로 나타내는 방법의 수
vector<int> result; //각 테스트케이스의 답을 저장해놓는 벡터

//1,2,3의 합으로 n을 나타낼 것.

int DP(int n) {
	if (n == 0) {
		num += 1;
		return 0;
	}

	if (n - 1 >= 0) DP(n - 1);
	if (n - 2 >= 0) DP(n - 2);
	if (n - 3 >= 0) DP(n - 3);
	return 0; //void형이 아닐 경우 return이 들어가는걸 잊지 말 것.
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		DP(n);
		result.push_back(num);
		num = 0;
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}
}
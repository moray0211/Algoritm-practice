#include <iostream>
#include <vector>

using namespace std;

int n; //n��° �Ǻ���ġ ���� ����ؾ���
vector<int> DP(21, -1);

int fiv(int n) {
	//�������
	if (DP[n] != -1) return DP[n];

	//���
	DP[n] = fiv(n - 1) + fiv(n - 2);
	return DP[n];
}

int main() {

	cin >> n;
	DP[0] = 0;
	DP[1] = 1;

	cout << fiv(n);

}
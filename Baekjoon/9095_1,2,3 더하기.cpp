#include <iostream>
#include <vector>
using namespace std;

int T; //�׽�Ʈ ���̽��� ����
int n; //����, 0<n<11
int num = 0; //1,2,3�� ������ ��Ÿ���� ����� ��
vector<int> result; //�� �׽�Ʈ���̽��� ���� �����س��� ����

//1,2,3�� ������ n�� ��Ÿ�� ��.

int DP(int n) {
	if (n == 0) {
		num += 1;
		return 0;
	}

	if (n - 1 >= 0) DP(n - 1);
	if (n - 2 >= 0) DP(n - 2);
	if (n - 3 >= 0) DP(n - 3);
	return 0; //void���� �ƴ� ��� return�� ���°� ���� �� ��.
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
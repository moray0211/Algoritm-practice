#include <iostream>
#include <string>
using namespace std;

int N; // 1�̻� N���Ͽ��� �Ѽ��� ������ ���
int digit = 1; //�ڸ���
int a = 1; //������ ��
int result = 0;
string str;
int num[5] = { -1, -1, -1, -1, -1 };

int main() {

	//�Ѽ��� ���信 ���� �� �ľ��Ұ�

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i % (digit * 10) == 0) { digit *= 10; a++; }

		if (digit <= 10) result++; //10���ڸ��������� �Ѽ�
		else {
			str = to_string(i);

			for (int j = 0; j < a; j++) { num[j] = stoi(str.substr(j, 1)); }

			int n = num[1] - num[0];
			bool isHansu = true;
			for (int j = 1; j < 5; j++) {
				if (num[j + 1] == -1) break;
				if (num[j] + n != num[j + 1]) { isHansu = false; break; }
			}
			if (isHansu) result++;
		}
	}

	cout << result;

}
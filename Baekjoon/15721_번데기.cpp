#include <iostream>
#include <string>

using namespace std;

int A; //������ �����ϴ� ����� ��
int T; //���ϰ��� �ϴ� ��°
bool isDegi; // ���̸� 0 ����� 1

int main() {

	/*
	nȸ�� = �� - ���� - �� - ���� - ��(x(n+1)) - ����(x(n+1))
	�� : 0
	���� : 1
	0 1 0 1 0(xn��) 1(xn��)
	*/

	cin >> A >> T >> isDegi;

	int result = 0;
	int p = 0; //���° ����ΰ�
	int k = 0; //���° �ܾ��ΰ� 4���� ��xn, 5���� ����xn (¦���� ��, Ȧ���� ����)
	int tmp = 0;
	int n = 1; //ȸ��

	int bbun = 0;
	int degi = 0;

	//���� �ڼ��� �б�
	while (true) {

		if (k % 2 == 0) bbun++;
		else degi++;

		if (isDegi && (degi == T)) break;
		if ((!isDegi) && (bbun == T)) break;

		if (k % 6 == 4 || k % 6 == 5) {
			tmp++;
			if (tmp == n + 1) {
				tmp = 0;
				k++;
			}
		}
		else k++;

		result++;
		p++;
		int person = 4 + (2 * n + 2);
		if (p%person == 0) {
			p = 0;
			n++;
		}

	}

	cout << result%A;

}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A; //�� ���� ������ ����
int B; //�� ���� ������ ����
int V; //�ö󰡾� �ϴ� ����

int day = 0; //��¥
int now = 0; //���� ����

int first = 0; //�ּڰ�
int last; //�ִ�
int mid; //�߰���

int main() {

	//���ѽð� 0.15��. ������ ������� Ǯ�� O(n)�̴�.
	//O(n) ���� 1�� �ȿ� ������ Ǯ���� ������ �Է��� ���� �� 1�ﰳ
	//���� ������ �ִ� �Է°��� 10�ﰳ -> �翬�� �ð� �ʰ�
	//�̺� Ž���� �ð����⵵�� O(logN)

	cin >> A >> B >> V;

	last = V;

	while (first <= last) {
		mid = (first + last) / 2;
		if (V > (mid - 1)*(A - B) + A) { //���ǹ� mid������ �ڴ� ���� �������� �� ���� ����ϸ� �ȵǱ� ����
			first = mid + 1;
		}
		else {
			//����� �Ÿ��� ��ǥ �Ÿ����� ũ�ų� �������
			last = mid - 1;
			day = mid;
		}
	}

	cout << day;

}
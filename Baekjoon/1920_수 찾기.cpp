#include <iostream>
#include <vector>
#include <algorithm> //sort �ð����⵵ O(N logN)
#include <cstdio> /

using namespace std;

int N; //N���� ����
int M; //M���� �� (N �ȿ� �ִ°�?)

	   /*�ش� ���� �ð� �ʰ��� ������ ����¹��� �־���.
	   cin�� cout�� printf�� scanf�� ���� �����ٴ� ��� ����ϱ�
	   õ������ ���ڸ� �Է¹�����, scanf�� �� 0.8�ʰ� �ɸ��� �� ����, cin�� �� 2�ʰ� �ɸ���.
	   cin�� cout�� ����� ��� �Է¹޴� ������ '����'�� ����.
	   */

int main() {

	scanf("%d", &N);
	vector <int> arr_N;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		arr_N.push_back(a);
	}

	cin >> M;
	vector <int> arr_M;
	for (int i = 0; i < M; i++) {
		int a;
		scanf("%d", &a);
		arr_M.push_back(a);
	}

	//����
	sort(arr_N.begin(), arr_N.end());

	for (int i = 0; i < M; i++) {
		//M���� ���� ���� Ž��
		int num = arr_M[i];
		int first = 0;
		int last = N - 1;
		int mid;
		bool hasNum = false;

		while (first <= last) {
			mid = (first + last) / 2;
			if (num == arr_N[mid]) { hasNum = true; break; }
			//�̺�Ž��

			if (num > arr_N[mid]) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		printf("%d\n", hasNum);
	}

}
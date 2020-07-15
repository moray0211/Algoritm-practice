#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; //���� ���� N��
	vector <int> lopes; //����
	vector <int> weight; //����

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		lopes.push_back(a);
	}
	sort(lopes.begin(), lopes.end()); //�������� ����

	int n = 1;
	for (int i = N - 1; i >= 0; i--) {
		weight.push_back(lopes[i] * n++);
		//������ �� �� �ִ� �߷�*����
		/*���� lopes�� ������������ ������ �Ǿ������Ƿ�,
		n�� n*m�߷��� �ø� �� �ִٸ�, (n+1)���� n*m �߷��� �ø� �� �ִ�.
		�׷��� �ؼ� �ø� �� �ִ� �߷��� �� ���� ū ���� �����ϸ� ������*/
	}
	sort(weight.begin(), weight.end());

	cout << weight[weight.size() - 1];

}
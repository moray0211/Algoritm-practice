#include <iostream>
#include <vector>

using namespace std;

int N; //�־��� ������ ����
int S; //������ �ϴ� ��
vector<int> number; //�־��� ����
int result = 0; //������ ����� ��
bool first = true; //ù��° �õ�����

void DFS(vector<int> number, int sum, int order) {
	if (sum == S && !first) result++;
	first = false;

	for (int i = order + 1; i < N; i++) {
		DFS(number, sum + number[i], i);
	}
}

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		number.push_back(n);
	}

	DFS(number, 0, -1);
	cout << result;

}
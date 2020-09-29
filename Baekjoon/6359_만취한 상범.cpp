#include <vector>
#include <iostream>
using namespace std;

int T; //�׽�Ʈ ���̽��� ����
int n; //n���� ��
vector<bool> room;
vector<int> result;

//k��° ���忡���� k�� ����� ���� ���
//n��° �������

int main() {

	cin >> T;

	while (T--) {
		cin >> n;
		room.assign(n + 1, true); //ù��° ���忡���� ���� ��� ����

		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j += i) room[j] = !room[j]; //���
		}

		int num = 0;
		for (int i = 1; i <= n; i++) { if (room[i]) num++; }
		result.push_back(num);
	}

	for (int i = 0; i < result.size(); i++) { cout << result[i] << endl; }

}
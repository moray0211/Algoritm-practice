#include <vector>
#include <iostream>
#include <string>
using namespace std;

int N; //������ ũ��
vector <vector<int>> movie;

//������ ����
void devide(int y, int x, int size) {

	if (size == 1) {
		cout << movie[y][x];
		return;
	}

	int first = movie[y][x];
	bool isCorrect = true;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (movie[i][j] != first) {
				isCorrect = false;
				break;
			}
		}
	}

	if (isCorrect) {
		cout << first;
	}
	else {
		int half = size / 2;
		cout << "(";
		devide(y, x, half); //���� ���
		devide(y, x + half, half); //���� ���
		devide(y + half, x, half); //���� �ϴ�
		devide(y + half, x + half, half); //���� �ϴ�
		cout << ")";
	}

}

int main() {
	cin >> N;
	movie.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			movie[i][j] = stoi(str.substr(j, 1));
		}
	}

	devide(0, 0, movie.size());
}
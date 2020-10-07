#include <vector>
#include <iostream>
#include <string>
using namespace std;

int N; //영상의 크기
vector <vector<int>> movie;

//구현에 주의
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
		devide(y, x, half); //좌측 상단
		devide(y, x + half, half); //우측 상단
		devide(y + half, x, half); //좌측 하단
		devide(y + half, x + half, half); //우측 하단
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
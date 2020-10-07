#include <vector>
#include <iostream>
using namespace std;

int N; //크기 : 2^N
int r, c; // (r,c)를 방문해야함
int result = 0;

int dy[4] = { 0, 0, 1, 1 };
int dx[4] = { 0, 1 , 0, 1 };
bool isEnd = false;

void devide(int y, int x, int this_size) {

	if (!isEnd) {

		if (this_size == 2) {
			for (int i = 0; i < 4; i++) {
				result++;
				if ((y + dy[i] == r) && (x + dx[i] == c)) {
					cout << result - 1;
					isEnd = true;
					return;
				}
			}
		}
		else {
			int half = this_size / 2;
			devide(y, x, half);
			devide(y, x + half, half);
			devide(y + half, x, half);
			devide(y + half, x + half, half);
		}

	}


}


int main() {
	cin >> N >> r >> c;
	int map_size = 2;
	for (int i = 0; i < N - 1; i++) map_size *= 2;

	devide(0, 0, map_size);
}
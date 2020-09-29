#include <vector>
#include <iostream>
using namespace std;

int T; //테스트 케이스의 개수
int n; //n개의 방
vector<bool> room;
vector<int> result;

//k번째 라운드에서는 k의 배수인 방을 토글
//n번째 라운드까지

int main() {

	cin >> T;

	while (T--) {
		cin >> n;
		room.assign(n + 1, true); //첫번째 라운드에서는 문을 모두 연다

		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j += i) room[j] = !room[j]; //토글
		}

		int num = 0;
		for (int i = 1; i <= n; i++) { if (room[i]) num++; }
		result.push_back(num);
	}

	for (int i = 0; i < result.size(); i++) { cout << result[i] << endl; }

}
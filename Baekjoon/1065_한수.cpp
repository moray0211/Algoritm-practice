#include <iostream>
#include <string>
using namespace std;

int N; // 1이상 N이하에서 한수의 개수를 출력
int digit = 1; //자릿수
int a = 1; //숫자의 수
int result = 0;
string str;
int num[5] = { -1, -1, -1, -1, -1 };

int main() {

	//한수의 개념에 대해 잘 파악할것

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i % (digit * 10) == 0) { digit *= 10; a++; }

		if (digit <= 10) result++; //10의자리수까지는 한수
		else {
			str = to_string(i);

			for (int j = 0; j < a; j++) { num[j] = stoi(str.substr(j, 1)); }

			int n = num[1] - num[0];
			bool isHansu = true;
			for (int j = 1; j < 5; j++) {
				if (num[j + 1] == -1) break;
				if (num[j] + n != num[j + 1]) { isHansu = false; break; }
			}
			if (isHansu) result++;
		}
	}

	cout << result;

}
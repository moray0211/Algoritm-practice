#include <iostream>
#include <string>

using namespace std;

int A; //게임을 진행하는 사람의 수
int T; //구하고자 하는 번째
bool isDegi; // 뻔이면 0 데기면 1

int main() {

	/*
	n회차 = 뻔 - 데기 - 뻔 - 데기 - 뻔(x(n+1)) - 데기(x(n+1))
	뻔 : 0
	데기 : 1
	0 1 0 1 0(xn번) 1(xn번)
	*/

	cin >> A >> T >> isDegi;

	int result = 0;
	int p = 0; //몇번째 사람인가
	int k = 0; //몇번째 단어인가 4번은 뻔xn, 5번은 데기xn (짝수는 뻔, 홀수는 데기)
	int tmp = 0;
	int n = 1; //회차

	int bbun = 0;
	int degi = 0;

	//조건 자세히 읽기
	while (true) {

		if (k % 2 == 0) bbun++;
		else degi++;

		if (isDegi && (degi == T)) break;
		if ((!isDegi) && (bbun == T)) break;

		if (k % 6 == 4 || k % 6 == 5) {
			tmp++;
			if (tmp == n + 1) {
				tmp = 0;
				k++;
			}
		}
		else k++;

		result++;
		p++;
		int person = 4 + (2 * n + 2);
		if (p%person == 0) {
			p = 0;
			n++;
		}

	}

	cout << result%A;

}
#include <iostream>
#include <vector>

using namespace std;

int n; //n번째 피보나치 수를 출력해야함
vector<int> DP(21, -1);

int fiv(int n) {
	//기저사례
	if (DP[n] != -1) return DP[n];

	//재귀
	DP[n] = fiv(n - 1) + fiv(n - 2);
	return DP[n];
}

int main() {

	cin >> n;
	DP[0] = 0;
	DP[1] = 1;

	cout << fiv(n);

}
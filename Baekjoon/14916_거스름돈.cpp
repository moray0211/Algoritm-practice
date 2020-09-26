#include <iostream>

using namespace std;

int result = -1;
bool isEnd = false;

void DFS(int n, int one, int two, int five) {

	if (!isEnd) {
		n -= one;
		if (n < 0) return;

		if (one == 5) five++;
		if (one == 2) two++;
		if (n == 0) {
			result = five + two;
			isEnd = true;
			return;
		}

		DFS(n, 5, two, five);
		DFS(n, 2, two, five);
	}

}

int main() {

	int n; //거스름돈의 액수
	cin >> n;
	DFS(n, 0, 0, 0);

	cout << result;
}
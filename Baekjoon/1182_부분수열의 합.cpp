#include <iostream>
#include <vector>

using namespace std;

int N; //주어진 정수의 개수
int S; //만들어야 하는 수
vector<int> number; //주어진 수들
int result = 0; //가능한 경우의 수
bool first = true; //첫번째 시도인지

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
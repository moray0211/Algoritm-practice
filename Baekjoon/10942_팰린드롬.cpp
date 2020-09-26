#include <vector>
#include <cstdio>
using namespace std;

int N; //수열의 크기
vector<int> number;
vector<vector<bool>> DP;
int M; //질문의 개수
int S, E; //S~E번째 수는 팰린드롬인가?
vector<int> result;

int main() {

	scanf("%d", &N);

	number.push_back(-1);
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		number.push_back(n);
	}

	scanf("%d", &M);

	DP.assign(N + 1, vector<bool>(N + 1, false));

	for (int i = 1; i <= N; i++) {
		DP[i][i] = true;
		if ((i + 1 <= N) && (number[i] == number[i + 1])) DP[i][i + 1] = true;
	}

	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= j; i++) {
			if ((i + 1 <= N) && (j - 1 >= 1) && (number[i] == number[j]) && (DP[i + 1][j - 1])) DP[i][j] = true;
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);
		result.push_back(DP[S][E]);
	}

	for (int i = 0; i < result.size(); i++) { printf("%d\n", result[i]); }

}
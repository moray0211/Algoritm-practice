#include <string>
#include <vector>

using namespace std;

int result = 0;

void DFS(int i, vector<int> numbers, int target, int sum) {

	if (i >= numbers.size()) { //끝까지 다 탐색했을경우
		if (sum == target) result++; //총합과 타겟넘버가 동일할경우 횟수 증감
		return;
		//총합과 타겟넘버가 동일하지 않을시, 함수 반환
		//하나의 배열 원소에 대해 +가 될 경우와 -가 될 경우가 재귀적으로 일어남에 유의
		//DFS = 두 정점이 서로 연결되어있는가?, 그래프의 모든 정점 방문. 더 깊게 들어감. 재귀Or스택 사용
	}
	DFS(i + 1, numbers, target, sum + numbers[i]);
	DFS(i + 1, numbers, target, sum - numbers[i]);
}

int solution(vector<int> numbers, int target) {

	DFS(0, numbers, target, 0);

	int answer = 0;
	answer = result;

	return answer;
}
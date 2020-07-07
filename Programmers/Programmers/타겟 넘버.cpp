#include <string>
#include <vector>

using namespace std;

int result = 0;

void DFS(int i, vector<int> numbers, int target, int sum) {

	if (i >= numbers.size()) { //������ �� Ž���������
		if (sum == target) result++; //���հ� Ÿ�ٳѹ��� �����Ұ�� Ƚ�� ����
		return;
		//���հ� Ÿ�ٳѹ��� �������� ������, �Լ� ��ȯ
		//�ϳ��� �迭 ���ҿ� ���� +�� �� ���� -�� �� ��찡 ��������� �Ͼ�� ����
		//DFS = �� ������ ���� ����Ǿ��ִ°�?, �׷����� ��� ���� �湮. �� ��� ��. ���Or���� ���
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
#include <string>
#include <vector>

using namespace std;

//lost : ü���� �������� �л� ��ȣ
//reserve : ������ ü������ �ִ� �л� ��ȣ (���������� �� ����)

/* Ž�������� Ǯ�� : �Ҿ���� �л��� ��,�� �� �����ϸ� �� ��ȣ�� �л� ü������ ������.
�׷��� �Ǹ� ���� �Ҿ���� �л��� �������� �þ��, ���� �� ��ȣ�� �л� ü������ ���ȴ���
1�� �л��� ������ 2�� �л��� �� �������̳�, 1�� �л��� �����ϰ� 2�� �л��� �������̳�
���� �Ȱ����� Ž���� ���� �Ӽ��� ����ȴ�. (��� �ܰ迡�� ������ ���� ������ �����ذ� ����)*/
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	int lostNum = lost.size();
	vector<bool> isLostStudent(n + 1, false); //��ȣ�� 0~4�� �ƴ�, 1~5 ����.
	vector<bool> isReserveStudent(n + 1, false);
	for (int i = 0; i<lost.size(); i++) { isLostStudent[lost[i]] = true; }
	for (int i = 0; i<reserve.size(); i++) {
		if (!isLostStudent[reserve[i]])
			isReserveStudent[reserve[i]] = true;
		else {
			lostNum--;
			isLostStudent[reserve[i]] = false;
		}
	}
	//���������� �ʾҴٸ� ���� ü���� �ִ� ������.
	//�������ߴٸ� �׷��� ���� ü������ �����Ƿ� lostNum�� �����ϰ�, isLostStudent�� false�� ����.

	for (int i = 0; i<lost.size(); i++) {

		if (isLostStudent[lost[i]]) { //�������� �л��̸鼭 ���� ü������ ���� ��츸
			if (lost[i] - 1 >= 0 && isReserveStudent[lost[i] - 1]) {
				isReserveStudent[lost[i] - 1] = false;
				answer++;
			}
			else if (lost[i] + 1 <= n && isReserveStudent[lost[i] + 1]) {
				isReserveStudent[lost[i] + 1] = false;
				answer++;
			}
		}

	}

	answer += (n - lostNum); //�Ҿ���� �л� ����

	return answer;
}
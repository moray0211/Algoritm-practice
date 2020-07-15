#include <string>
#include <vector>

using namespace std;

//lost : 체육복 도난당한 학생 번호
//reserve : 여벌의 체육복이 있는 학생 번호 (도난당했을 수 있음)

/* 탐욕적으로 풀기 : 잃어버린 학생의 앞,뒤 중 가능하면 앞 번호의 학생 체육복을 빌린다.
그렇게 되면 다음 잃어버린 학생은 선택지가 늘어나며, 만약 뒷 번호의 학생 체육복을 빌렸더라도
1번 학생이 빌리고 2번 학생이 못 빌린것이나, 1번 학생이 포기하고 2번 학생이 빌린것이나
수는 똑같으니 탐욕적 선택 속성이 증명된다. (모든 단계에서 선택한 답을 포함한 최적해가 존재)*/
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	int lostNum = lost.size();
	vector<bool> isLostStudent(n + 1, false); //번호는 0~4가 아닌, 1~5 형식.
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
	//도난당하지 않았다면 여벌 체육복 있는 것으로.
	//도난당했다면 그래도 입을 체육복은 있으므로 lostNum을 감산하고, isLostStudent를 false로 설정.

	for (int i = 0; i<lost.size(); i++) {

		if (isLostStudent[lost[i]]) { //도난맞은 학생이면서 여벌 체육복도 없을 경우만
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

	answer += (n - lostNum); //잃어버린 학생 제외

	return answer;
}
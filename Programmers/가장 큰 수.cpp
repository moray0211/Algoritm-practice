#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	string thisA = to_string(a);
	string thisB = to_string(b);
	string aFirst = thisA + thisB;
	string bFirst = thisB + thisA;
	return aFirst<bFirst; //aFirst가 더 작을때만 1이 리턴되므로, 오름차순 정렬이 된다.
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);
	for (int i = numbers.size() - 1; i >= 0; i--) {
		answer += to_string(numbers[i]);
	}
	//만약 0이 나왔다면, 0은 무조건 뒤에 배치되므로 맨 앞에 0이 배치된다는것은 나머지 값도 0임을 뜻함.
	if (answer[0] == '0') answer = "0"; //만약 비어있다면 답은 0
	return answer;
}
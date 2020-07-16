#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	string thisA = to_string(a);
	string thisB = to_string(b);
	string aFirst = thisA + thisB;
	string bFirst = thisB + thisA;
	return aFirst<bFirst; //aFirst�� �� �������� 1�� ���ϵǹǷ�, �������� ������ �ȴ�.
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);
	for (int i = numbers.size() - 1; i >= 0; i--) {
		answer += to_string(numbers[i]);
	}
	//���� 0�� ���Դٸ�, 0�� ������ �ڿ� ��ġ�ǹǷ� �� �տ� 0�� ��ġ�ȴٴ°��� ������ ���� 0���� ����.
	if (answer[0] == '0') answer = "0"; //���� ����ִٸ� ���� 0
	return answer;
}
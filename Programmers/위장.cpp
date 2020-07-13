#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> clothesMap;

int solution(vector<vector<string>> clothes) {

	for (int i = 0; i<clothes.size(); i++) {
		clothesMap[clothes[i][1]]++; //�ش� key���� �ش��ϴ� ���� � �ִ��� ���
	}

	int result = 1;
	for (pair<string, int> p : clothesMap) {
		result *= p.second + 1;
		// (nCr+1) * (nCr+1) * ... (nCr+1) -1
		// n���� �� �߿� 1���� �̴� ���� + 1(���� �ʴ� ����) ���� ���ϰ�, -1�Ѵ�. (���� ���� �ʴ� ���... �ϳ��� �Ծ�� �ϹǷ�.)
		// �� ī�װ��� ���� �ϳ����� ���� �� �����Ƿ�, r�� 1�� �ȴ�.
	}
	result -= 1;

	return result;
}
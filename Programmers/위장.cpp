#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> clothesMap;

int solution(vector<vector<string>> clothes) {

	for (int i = 0; i<clothes.size(); i++) {
		clothesMap[clothes[i][1]]++; //해당 key값에 해당하는 옷이 몇개 있는지 등록
	}

	int result = 1;
	for (pair<string, int> p : clothesMap) {
		result *= p.second + 1;
		// (nCr+1) * (nCr+1) * ... (nCr+1) -1
		// n개의 옷 중에 1개를 뽑는 조합 + 1(뽑지 않는 조합) 들을 곱하고, -1한다. (전부 입지 않는 경우... 하나는 입어야 하므로.)
		// 한 카테고리의 옷은 하나씩만 입을 수 있으므로, r은 1이 된다.
	}
	result -= 1;

	return result;
}
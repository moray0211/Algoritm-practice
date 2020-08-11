#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int SIZE = citations.size();
	vector<int> arr;

	sort(citations.begin(), citations.end()); //Á¤·Ä
	for (int i = 0; i<SIZE; i++) {
		int tmp = 0;
		for (int j = 0; j<SIZE; j++) {
			if (citations[j] >= citations[i]) tmp++;
		}
		if (tmp >= citations[i]) arr.push_back(citations[i]);
		else {
			for (int k = citations[i] - 1; k >= 0; k--) {
				if (tmp >= k) arr.push_back(k);
			}
		}
	}
	int answer;
	if (arr.empty()) answer = 0;
	else {
		sort(arr.begin(), arr.end());
		answer = arr[arr.size() - 1];
	}
	return answer;
}
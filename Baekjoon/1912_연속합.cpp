#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int RESULT_MIN = -100000001;
int result_max = RESULT_MIN;
int result;
int n;
vector<int> arr;

void DP(int index) {
	if (index == n) return;
	int now = arr[index];
	
	if (index == 0) { result = now; }
	else {
		if (result + now < now) {
			//★지금까지 연속합보다 현재 원소가 더 크다면 버린다.
			result = now;
		}
		else {
			result += now;
		}
	}
	result_max = (result_max > result) ? result_max : result;
	DP(index + 1);
	
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	DP(0);
	printf("%d", result_max);
}
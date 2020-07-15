#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; //로프 갯수 N개
	vector <int> lopes; //로프
	vector <int> weight; //무게

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		lopes.push_back(a);
	}
	sort(lopes.begin(), lopes.end()); //오름차순 정렬

	int n = 1;
	for (int i = N - 1; i >= 0; i--) {
		weight.push_back(lopes[i] * n++);
		//로프가 끌 수 있는 중량*순서
		/*현재 lopes는 오름차순으로 정렬이 되어있으므로,
		n이 n*m중량을 올릴 수 있다면, (n+1)또한 n*m 중량을 올릴 수 있다.
		그렇게 해서 올릴 수 있는 중량들 중 가장 큰 값을 선택하면 최적해*/
	}
	sort(weight.begin(), weight.end());

	cout << weight[weight.size() - 1];

}
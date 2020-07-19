#include <iostream>
#include <vector>
#include <algorithm> //sort 시간복잡도 O(N logN)
#include <cstdio> /

using namespace std;

int N; //N개의 정수
int M; //M개의 수 (N 안에 있는가?)

	   /*해당 문제 시간 초과의 이유는 입출력문에 있었음.
	   cin과 cout은 printf와 scanf에 비해 느리다는 사실 기억하기
	   천만개의 숫자를 입력받을때, scanf는 약 0.8초가 걸리는 데 비해, cin은 약 2초가 걸린다.
	   cin과 cout을 사용할 경우 입력받는 숫자의 '갯수'에 주의.
	   */

int main() {

	scanf("%d", &N);
	vector <int> arr_N;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		arr_N.push_back(a);
	}

	cin >> M;
	vector <int> arr_M;
	for (int i = 0; i < M; i++) {
		int a;
		scanf("%d", &a);
		arr_M.push_back(a);
	}

	//정렬
	sort(arr_N.begin(), arr_N.end());

	for (int i = 0; i < M; i++) {
		//M개의 수에 대한 탐색
		int num = arr_M[i];
		int first = 0;
		int last = N - 1;
		int mid;
		bool hasNum = false;

		while (first <= last) {
			mid = (first + last) / 2;
			if (num == arr_N[mid]) { hasNum = true; break; }
			//이분탐색

			if (num > arr_N[mid]) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		printf("%d\n", hasNum);
	}

}
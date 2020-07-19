#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A; //낮 동안 오르는 높이
int B; //밤 동안 내리는 높이
int V; //올라가야 하는 높이

int day = 0; //날짜
int now = 0; //현재 높이

int first = 0; //최솟값
int last; //최댓값
int mid; //중간값

int main() {

	//제한시간 0.15초. 무식한 방법으로 풀면 O(n)이다.
	//O(n) 으로 1초 안에 문제를 풀려면 가능한 입력의 갯수 약 1억개
	//현재 문제의 최대 입력값은 10억개 -> 당연히 시간 초과
	//이분 탐색의 시간복잡도는 O(logN)

	cin >> A >> B >> V;

	last = V;

	while (first <= last) {
		mid = (first + last) / 2;
		if (V > (mid - 1)*(A - B) + A) { //조건문 mid번에서 자는 동안 떨어지는 것 까지 계산하면 안되기 때문
			first = mid + 1;
		}
		else {
			//계산한 거리가 목표 거리보다 크거나 같을경우
			last = mid - 1;
			day = mid;
		}
	}

	cout << day;

}
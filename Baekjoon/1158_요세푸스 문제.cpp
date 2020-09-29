#include <vector>
#include <iostream>
using namespace std;

int N; //1번~N번
int K; //K번째 사람

vector<int> circle;
vector<int> result;

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		circle.push_back(i + 1); //0번 배열에 1이 들어감
	}

	int index = 0;
	while (!circle.empty()) {
		int size = circle.size();
		result.push_back(circle[(index + (K - 1)) % size]);
		circle.erase(circle.begin() + ((index + (K - 1)) % size));

		index = (index + (K - 1)) % size;
	}

	cout << "<" << result[0];
	for (int i = 1; i < result.size(); i++) {
		cout << ", " << result[i];
	}
	cout << ">";

}
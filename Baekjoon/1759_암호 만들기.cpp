#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L; //암호에 쓰이는 알파벳 수
int C; //주어진 알파벳 수
vector<char> alphabet;
vector<vector<char>> result; //나올 수 있는 패스워드 

							 //최소 한개의 모음과 두개의 자음
void DFS(vector<char> alphabet, int num, int ja, int mo, int cnt, vector<char> password) {

	if (cnt == L) {
		if ((ja >= 2 && mo >= 1)) result.push_back(password);
		return;
	}

	for (int i = num + 1; i < C; i++) {
		password.push_back(alphabet[i]);
		char a = alphabet[i];

		if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') DFS(alphabet, i, ja, mo + 1, cnt + 1, password);
		else DFS(alphabet, i, ja + 1, mo, cnt + 1, password);
		password.pop_back(); //현재 함수에서 가지고 있는 패스워드가 조건에 부합하지 않으므로 pop 후 다음 DFS
	}

}

int main() {

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char a;
		cin >> a;
		alphabet.push_back(a);
	}

	sort(alphabet.begin(), alphabet.end());
	int cnt = 0;

	vector<char> password;
	DFS(alphabet, -1, 0, 0, 0, password);

	for (int i = 0; i < result.size(); i++) {
		string str(result[i].begin(), result[i].end());
		cout << str << endl;
	}

}
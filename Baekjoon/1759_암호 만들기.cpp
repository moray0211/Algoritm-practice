#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L; //��ȣ�� ���̴� ���ĺ� ��
int C; //�־��� ���ĺ� ��
vector<char> alphabet;
vector<vector<char>> result; //���� �� �ִ� �н����� 

							 //�ּ� �Ѱ��� ������ �ΰ��� ����
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
		password.pop_back(); //���� �Լ����� ������ �ִ� �н����尡 ���ǿ� �������� �����Ƿ� pop �� ���� DFS
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
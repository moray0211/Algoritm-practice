#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M; //�л� 1��~N��. M�� ��
vector<vector<int>> student;
vector<bool> visited;
stack<int> my_stack;

void dfs(int n) {
	visited[n] = true;

	for (int i = 0; i <student[n].size(); i++) {
		if (!visited[student[n][i]]) dfs(student[n][i]);
	}

	my_stack.push(n);
}

int main() {

	cin >> N >> M;
	student.resize(N + 1);
	visited.assign(N + 1, false);

	for (int i = 0; i < M; i++) {
		int front, back;
		cin >> front >> back;
		student[front].push_back(back); //front->back ������ ǥ��
										//front�� 1���� N������°Ϳ� ����.
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i);
	}

	while (!my_stack.empty()) {
		cout << my_stack.top() << " ";
		my_stack.pop();
		//���� �������� ���� �� �ִ�. ������ ��.
	}

}
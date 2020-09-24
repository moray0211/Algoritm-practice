#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int N; //������ ��
int M; //���� Ǫ�� ���� ���� ������ ���� ������ ����

	   /* !!���� ���� ����!! */

vector<vector<int>> pre_pro; //���� Ǯ��� �ϴ� ������
vector<vector<int>> next_pro; //�� ������ ǰ���ν� Ǯ �� �ִ� ������

int main() {
	cin >> N >> M;

	pre_pro.resize(N + 2); //N���� ����
	next_pro.resize(N + 2);

	priority_queue<int, vector<int>, greater<int>> single_pro; //���� Ǯ�� ���� ������ ���� Ǯ�� ������
	vector<bool> used(32002, false);

	for (int i = 0; i < M; i++) {
		//���� Ǯ�� ���� ������ ������ ���� �� �ִ�.
		//���� ���� Ǯ�� ���� ������ ������ ���� �� �ִ�. (�� ���� ������ ���� �� �ִ�)
		int a, b; //a�� ������ b�� �������� ���� Ǯ����Ѵ�
		cin >> a >> b;
		next_pro[a].push_back(b); //next_pro[��ȣ] ���� (��ȣ �� ������ ���� Ǯ��� �ϴ� ������ �����Ǿ��� ����) �� �� �ִ�.
		pre_pro[b].push_back(a); //pre_pro[��ȣ] ���� (���� Ǯ��� �ϴ� ����) �� �� �ִ�.
	}

	//���� Ǫ�� ���� ���� ������ ���� ���, ������ �� ������ ���� Ǯ��� ������
	//�� ������ Ǯ�� ����, ������ �־��� ���� ������ ���߿� Ǯ� �ȴ�

	//�ٷ� Ǯ �� �ִ� ������ ����
	for (int i = 1; i <= N; i++) {
		if (pre_pro[i].empty()) single_pro.push(i);
	}

	while (!single_pro.empty()) {

		int tmp = single_pro.top();
		if (!used[tmp]) cout << tmp << " ";
		used[tmp] = true;
		single_pro.pop();

		for (int i = 0; i < next_pro[tmp].size(); i++) {
			bool isCorrect = true;
			for (int j = 0; j < pre_pro[next_pro[tmp][i]].size(); j++) {
				if (!used[pre_pro[next_pro[tmp][i]][j]]) {
					isCorrect = false;
					break;
				}
			}
			if (isCorrect) single_pro.push(next_pro[tmp][i]);
		}

	}

}
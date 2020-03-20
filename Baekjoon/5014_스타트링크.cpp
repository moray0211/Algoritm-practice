#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
//�ǹ��� 1~F��, ��ŸƮ��ũ�� G��
//��ȣ�� �ִ� ���� S��.
//���� U���� ���� ��ư, �Ʒ��� D���� ���� ��ư �ΰ���.
vector<vector<int>> layer;
vector<bool> visited;
queue<int> q;
vector<int> dis;

void BFS(int start) {
	visited[start] = true;
	dis[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < layer[here].size(); i++) {
			int there = layer[here][i];
			if (!visited[there]) {
				visited[there] = true;
				q.push(there);
				dis[there] = dis[here] + 1;
			}
		}
	}
}

int main() {

	//S->G�� ���� ���� ������ �ϴ� ��ư�� �ּڰ� ����ϱ�.
	//�̷��� �ִ� ��� ���� ���� BFS�� ����Ѵ�.
	cin >> F >> S >> G >> U >> D;
	layer.resize(F + 1);
	visited.resize(F + 1);
	dis.assign(F + 1, -1);

	for (int i = 1; i <= F; i++) {
		//U�� ��, D�� �Ʒ��� �ش� ���� ���� ���� ���������ʹ� �������� �ʴ´�.
		if (i + U <= F) layer[i].push_back(i + U);
		if (i - D >= 1) layer[i].push_back(i - D);
	}

	BFS(S);
	if (dis[G] == -1) { cout << "use the stairs"; }
	else { cout << dis[G]; }

}
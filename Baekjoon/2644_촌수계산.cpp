
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> person;
vector<bool> visited;
vector<int> dis;
queue<int> Q;

void bfs(int start) {
	Q.push(start); //������ push. ���⼭ Q�� �湮�� ������ ���̴�.
	visited[start] = true;
	dis[start] = 0; //���� ������ �Ÿ��� 0

	while (!Q.empty()) {
		int here = Q.front();
		Q.pop(); //�湮����
		for (int i = 0; i < person[here].size(); i++) {
			int there = person[here][i];
			if (!visited[there]) {
				visited[there] = true;
				dis[there] = dis[here] + 1;
				Q.push(there);
			}
		}
	}
}

int main() {

	int n; //��ü ����� ��
	int per1, per2; //�̼��� ��Ÿ���� �ϴ� ���
	int m; //�θ� �ڽĵ� ���� ������ ����

	cin >> n;
	cin >> per1 >> per2;
	cin >> m;
	person.resize(n + 1);
	visited.assign(n + 1, false);
	dis.assign(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int x, y; //x�� y�� �θ� ��ȣ
		cin >> x >> y;
		person[x].push_back(y); //��->�Ʒ� �̵�
		person[y].push_back(x); //�Ʒ�->�� �̵�
	}

	bfs(per1);
	cout << dis[per2];

}
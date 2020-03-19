#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V; //������ ����N, ������ ����M, Ž���� ������ ������ ��ȣ V
vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;
queue<int> save_q;

//Stack�� �̿��ϴ� DFS�� ��͸� �̿��ϴ� DFS �����ؼ� �����α�
void DFS(int start) {
	cout << start << " ";
	visited[start] = true;
	for (int i = 0; i < adj[start].size(); i++) {
		if (!visited[adj[start][i]]) DFS(adj[start][i]);
	}
}

void BFS(int start) {
	visited[start] = true;
	q.push(start);
	save_q.push(start);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (!visited[there]) {
				visited[there] = true;
				q.push(there);
				save_q.push(there);
			}
		}
	}
}

int main() {

	//���� ��ȣ�� 1��~N��
	cin >> N >> M >> V;
	//������ �ִ� ������ 10,000���̴�. 
	adj.resize(10001);
	visited.assign(10001, false);

	for (int i = 0; i < M; i++) {
		int x, y; //������ �����ϴ� �� ������ ��ȣ
		cin >> x >> y;
		//�Է����� �־����� ������ ������̴�.
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	//������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�Ѵ�.
	for (int i = 0; i <adj.size(); i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(V);

	visited.assign(10001, false);
	cout << endl;

	BFS(V);
	while (!save_q.empty()) {
		cout << save_q.front() << " ";
		save_q.pop();
	}

}
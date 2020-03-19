#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V; //정점의 갯수N, 간선의 갯수M, 탐색을 시작할 정점의 번호 V
vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;
queue<int> save_q;

//Stack을 이용하는 DFS와 재귀를 이용하는 DFS 구분해서 익혀두기
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

	//정점 번호는 1번~N번
	cin >> N >> M >> V;
	//간선의 최대 개수는 10,000개이다. 
	adj.resize(10001);
	visited.assign(10001, false);

	for (int i = 0; i < M; i++) {
		int x, y; //간선이 연결하는 두 정점의 번호
		cin >> x >> y;
		//입력으로 주어지는 간선은 양방향이다.
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	//정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문한다.
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
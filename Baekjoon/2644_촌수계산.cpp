
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
	Q.push(start); //시작점 push. 여기서 Q는 방문할 예정인 곳이다.
	visited[start] = true;
	dis[start] = 0; //시작 지점의 거리는 0

	while (!Q.empty()) {
		int here = Q.front();
		Q.pop(); //방문했음
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

	int n; //전체 사람의 수
	int per1, per2; //촌수를 나타내야 하는 사람
	int m; //부모 자식들 간의 관계의 개수

	cin >> n;
	cin >> per1 >> per2;
	cin >> m;
	person.resize(n + 1);
	visited.assign(n + 1, false);
	dis.assign(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int x, y; //x는 y의 부모 번호
		cin >> x >> y;
		person[x].push_back(y); //위->아래 이동
		person[y].push_back(x); //아래->위 이동
	}

	bfs(per1);
	cout << dis[per2];

}
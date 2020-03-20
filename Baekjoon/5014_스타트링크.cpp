#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
//건물은 1~F층, 스타트링크는 G층
//강호가 있는 곳은 S층.
//위로 U층을 가는 버튼, 아래로 D층을 가는 버튼 두개뿐.
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

	//S->G로 가기 위해 눌러야 하는 버튼의 최솟값 출력하기.
	//이러한 최단 경로 문제 또한 BFS를 사용한다.
	cin >> F >> S >> G >> U >> D;
	layer.resize(F + 1);
	visited.resize(F + 1);
	dis.assign(F + 1, -1);

	for (int i = 1; i <= F; i++) {
		//U층 위, D층 아래에 해당 층이 없을 때는 엘레베이터는 움직이지 않는다.
		if (i + U <= F) layer[i].push_back(i + U);
		if (i - D >= 1) layer[i].push_back(i - D);
	}

	BFS(S);
	if (dis[G] == -1) { cout << "use the stairs"; }
	else { cout << dis[G]; }

}
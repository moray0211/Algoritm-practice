#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int N; //정점의 개수
int M; //간선의 개수

vector<vector<int>> line;
vector<bool> visited;

int result = 0;

bool first = true;
void BFS(int here) {

	if (visited[here]) return;
	visited[here] = true;

	//점일경우에도 연결요소
	if (line[here].size() == 0) { result++; return; }

	for (int i = 0; i < line[here].size(); i++) {
		int next = line[here][i];
		if (!visited[next]) BFS(next);
		else {
			if (first) {
				result++;
				first = false;
			}
		}
	}

}

int main() {

	scanf("%d %d", &N, &M);
	line.resize(N + 1);
	visited.assign(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		line[u].push_back(v);
		line[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		BFS(i);
		first = true;
	}

	printf("%d", result);
}
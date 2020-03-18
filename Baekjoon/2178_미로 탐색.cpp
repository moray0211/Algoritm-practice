#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<bool>> grid;
vector<vector<bool>> visited;
vector<vector<int>> dis;
queue<pair<int, int>> Q;
int N, M; //N개의 줄 M개의 미로

void bfs(int x, int y) {

	visited[x][y] = true;
	dis[x][y] = 0;
	Q.push(make_pair(x, y));

	while (!Q.empty()) {

		int a, b;
		a = Q.front().first;
		b = Q.front().second;
		Q.pop();

		if (a > 0 && grid[a - 1][b] && !visited[a - 1][b]) {
			visited[a - 1][b] = true;
			Q.push(make_pair(a - 1, b));
			dis[a - 1][b] = dis[a][b] + 1;
		}
		if (a < N - 1 && grid[a + 1][b] && !visited[a + 1][b]) {
			visited[a + 1][b] = true;
			Q.push(make_pair(a + 1, b));
			dis[a + 1][b] = dis[a][b] + 1;
		}
		if (b > 0 && grid[a][b - 1] && !visited[a][b - 1]) {
			visited[a][b - 1] = true;
			Q.push(make_pair(a, b - 1));
			dis[a][b - 1] = dis[a][b] + 1;
		}
		if (b < M - 1 && grid[a][b + 1] && !visited[a][b + 1]) {
			visited[a][b + 1] = true;
			Q.push(make_pair(a, b + 1));
			dis[a][b + 1] = dis[a][b] + 1;
		}

	}

}

int main() {

	cin >> N >> M;
	grid.assign(N, vector<bool>(M, false));
	visited.assign(N, vector<bool>(M, false));
	dis.assign(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			//string에 포함된 substr 함수 : [pos,pos + count) 를 자른다.
			grid[i][j] = stoi(str.substr(j, 1)); //string에 속한 stoi 함수 : string to int
		}
	}

	bfs(0, 0);
	cout << dis[N - 1][M - 1] + 1;

}
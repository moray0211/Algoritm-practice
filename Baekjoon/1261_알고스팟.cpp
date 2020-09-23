#include <string>
#include <vector>
#include <iostream>
//#include <queue>
//#include <utility>

using namespace std;
const int MAX_N = 100000; //최댓값에 주의

int M, N; //가로M 세로N
vector<vector<bool>> maze;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// [DFS]

vector<vector<bool>> visited;
vector<vector<int>> min_wall_n;
int result;

void DFS(int x, int y, int wall) {

	if (min_wall_n[x][y] > wall) {
		min_wall_n[x][y] = wall;
	}
	else return;

	if (x == M - 1 && y == N - 1) {
		result = wall;
		return;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int thisX = x + dx[i];
		int thisY = y + dy[i];
		if ((thisX >= 0 && thisX < M) && (thisY >= 0 && thisY < N)) {
			if (!visited[thisX][thisY]) {
				int isWall = maze[thisX][thisY];
				DFS(thisX, thisY, wall + isWall);
				visited[thisX][thisY] = false; //DFS를 마치고 돌아왔을 경우 방문 해제
			}
		}
	}
}

// [BFS : 최단거리]
// 해당 문제는 최단 '거리' 가 아닌 조건에 맞는 최소 갯수이다.

//queue<pair<int, int>> q;
//vector<vector<bool>> discovered(101, vector<bool>(101, false));
//vector<vector<int>> wall(101,vector<int>(101,0));

//void BFS() {
//	q.push(make_pair(0,0)); //기본 발견 및 방문
//	discovered[0][0] = true;
//	pair<int, int> tmp;
//
//	while (!q.empty()) { //더이상 방문할 곳이 없을 때 까지 방문
//		tmp = q.front();
//		if (maze[tmp.first][tmp.second]) wall[tmp.first][tmp.second]++; //벽이 있다면 부순다
//		q.pop(); //방문
//
//		//다음 위치 탐색
//		for (int i = 0; i < 4; i++) {
//			int thisX = tmp.first + dx[i];
//			int thisY = tmp.second + dy[i];
//			if ((thisX >= 0 && thisX < M) && (thisY >= 0 && thisY < N)) {
//				if (!discovered[thisX][thisY]) {
//					discovered[thisX][thisY] = true; //발견
//					wall[thisX][thisY] = wall[tmp.first][tmp.second];
//					q.push(make_pair(thisX, thisY));
//				}
//			}
//		}
//	}
//}

int main() {
	cin >> N >> M;
	maze.assign(M, vector<bool>(N, false));
	visited.assign(M, vector<bool>(N, false));
	min_wall_n.assign(M, vector<int>(N, MAX_N));

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			int a = stoi(str.substr(j, 1)); //stoi 숙지
			maze[i][j] = a;
		}
	}

	DFS(0, 0, 0);
	cout << result;

}
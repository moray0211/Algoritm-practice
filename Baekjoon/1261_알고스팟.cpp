#include <string>
#include <vector>
#include <iostream>
//#include <queue>
//#include <utility>

using namespace std;
const int MAX_N = 100000; //�ִ񰪿� ����

int M, N; //����M ����N
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
				visited[thisX][thisY] = false; //DFS�� ��ġ�� ���ƿ��� ��� �湮 ����
			}
		}
	}
}

// [BFS : �ִܰŸ�]
// �ش� ������ �ִ� '�Ÿ�' �� �ƴ� ���ǿ� �´� �ּ� �����̴�.

//queue<pair<int, int>> q;
//vector<vector<bool>> discovered(101, vector<bool>(101, false));
//vector<vector<int>> wall(101,vector<int>(101,0));

//void BFS() {
//	q.push(make_pair(0,0)); //�⺻ �߰� �� �湮
//	discovered[0][0] = true;
//	pair<int, int> tmp;
//
//	while (!q.empty()) { //���̻� �湮�� ���� ���� �� ���� �湮
//		tmp = q.front();
//		if (maze[tmp.first][tmp.second]) wall[tmp.first][tmp.second]++; //���� �ִٸ� �μ���
//		q.pop(); //�湮
//
//		//���� ��ġ Ž��
//		for (int i = 0; i < 4; i++) {
//			int thisX = tmp.first + dx[i];
//			int thisY = tmp.second + dy[i];
//			if ((thisX >= 0 && thisX < M) && (thisY >= 0 && thisY < N)) {
//				if (!discovered[thisX][thisY]) {
//					discovered[thisX][thisY] = true; //�߰�
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
			int a = stoi(str.substr(j, 1)); //stoi ����
			maze[i][j] = a;
		}
	}

	DFS(0, 0, 0);
	cout << result;

}
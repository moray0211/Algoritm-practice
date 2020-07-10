#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int M, N; //M*N 크기 (가로*세로)
vector<vector<int>> box; // [세로][가로] == [N][M]
queue<pair<int, int>> goodTomato;
queue<pair<int, int>> tmp;
int time = -1; //걸리는 시간

void BFS() {

	vector<vector<bool>> discovered(N, vector<bool>(M, false));
	int dy[4] = { 1, 0, -1, 0 };
	int dx[4] = { 0, 1, 0, -1 };

	while (!tmp.empty()) { //처음에 주어진 익은 토마토들
		int y = tmp.front().first;
		int x = tmp.front().second;
		discovered[y][x] = true;
		tmp.pop();

		goodTomato.push(make_pair(y, x));
	}

	//익은 토마토들이 다른 토마토를 익히는것을 한 턴으로 쳐야함.
	while (!goodTomato.empty()) {

		time++; //한 턴 경과

		while (!goodTomato.empty()) { //익은 토마토를 기점으로 다른 토마토를 익히는게 한 턴.

			int here_y = goodTomato.front().first;
			int here_x = goodTomato.front().second;
			box[here_y][here_x] = 1; //토마토를 익힘
			goodTomato.pop();

			for (int i = 0; i < 4; i++) { //인접한 토마토 탐색

				if (here_y + dy[i] >= 0 && here_y + dy[i] < N && here_x + dx[i] >= 0 && here_x + dx[i] < M) {
					if (!discovered[here_y + dy[i]][here_x + dx[i]] && box[here_y + dy[i]][here_x + dx[i]] == 0) {
						discovered[here_y + dy[i]][here_x + dx[i]] = true; //발견
						tmp.push(make_pair(here_y + dy[i], here_x + dx[i])); //다음턴에 익을 토마토 임시저장
					}
				}

			}

		}

		while (!tmp.empty()) {
			goodTomato.push(tmp.front());
			tmp.pop();
		}

	}

}

int check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) return -1;
		}
	}
	return time;
}

int main() {
	cin >> M >> N;
	box.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			box[i][j] = a;
			if (box[i][j] == 1) tmp.push(make_pair(i, j));
		}
	}

	//BFS
	BFS();
	int result = check();
	cout << result;
}
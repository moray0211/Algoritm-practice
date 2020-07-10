#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int M, N; //M*N ũ�� (����*����)
vector<vector<int>> box; // [����][����] == [N][M]
queue<pair<int, int>> goodTomato;
queue<pair<int, int>> tmp;
int time = -1; //�ɸ��� �ð�

void BFS() {

	vector<vector<bool>> discovered(N, vector<bool>(M, false));
	int dy[4] = { 1, 0, -1, 0 };
	int dx[4] = { 0, 1, 0, -1 };

	while (!tmp.empty()) { //ó���� �־��� ���� �丶���
		int y = tmp.front().first;
		int x = tmp.front().second;
		discovered[y][x] = true;
		tmp.pop();

		goodTomato.push(make_pair(y, x));
	}

	//���� �丶����� �ٸ� �丶�並 �����°��� �� ������ �ľ���.
	while (!goodTomato.empty()) {

		time++; //�� �� ���

		while (!goodTomato.empty()) { //���� �丶�並 �������� �ٸ� �丶�並 �����°� �� ��.

			int here_y = goodTomato.front().first;
			int here_x = goodTomato.front().second;
			box[here_y][here_x] = 1; //�丶�並 ����
			goodTomato.pop();

			for (int i = 0; i < 4; i++) { //������ �丶�� Ž��

				if (here_y + dy[i] >= 0 && here_y + dy[i] < N && here_x + dx[i] >= 0 && here_x + dx[i] < M) {
					if (!discovered[here_y + dy[i]][here_x + dx[i]] && box[here_y + dy[i]][here_x + dx[i]] == 0) {
						discovered[here_y + dy[i]][here_x + dx[i]] = true; //�߰�
						tmp.push(make_pair(here_y + dy[i], here_x + dx[i])); //�����Ͽ� ���� �丶�� �ӽ�����
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
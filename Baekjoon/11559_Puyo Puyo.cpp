#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<vector<char>> grid; //grid[��][��ȣ]
vector<vector<bool>> visited;
int result = 0; //���� Ƚ��. �ѹ��� ���� �ѿ���� ������ ����� �ѹ����� ġ�°Ϳ� ����.
int dx[4] = { 0, 1, 0 , -1 };
int dy[4] = { -1, 0, 1, 0 };
int puyo = 0; //�ѿ��� ��. 4���� �𿩾� ������
char color = '.'; //����
stack<pair<int, int>> puyoLocation;

void DFS_gravity(int x, int y) {

	//X�� Y ��ġ ������� Ȯ���ϱ�. ��� �� ���� ����...
	if (x > 0 && grid[x - 1][y] != '.' && grid[x][y] == '.') {
		grid[x][y] = grid[x - 1][y];
		grid[x - 1][y] = '.';
		DFS_gravity(x - 1, y);
	}
}

void DFS(int x, int y) {
	visited[x][y] = true;

	if (puyo == 0 && !puyoLocation.empty()) {
		while (!puyoLocation.empty()) puyoLocation.pop();
	}

	if (grid[x][y] != '.') {
		//���� ����
		color = grid[x][y];
		//�ѿ� �� ����
		puyo++;
		puyoLocation.push(make_pair(x, y)); //��ǥ ����
	}

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX >= 0 && newX < 12 && newY >= 0 && newY < 6) {
			if ((!visited[newX][newY]) && grid[newX][newY] == color) {
				DFS(newX, newY);
			}
		}
	}

}


int main() {
	//ĭ�� 6*12��.
	//����� . �� �ʱ�ȭ
	grid.assign(12, vector<char>(6, '.'));
	visited.assign(12, vector<bool>(6, false));

	//�ѱ��ھ� �߶� �Է¹ޱ�
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			char a;
			a = cin.get();
			grid[i][j] = a;
		}
		cin.get();
	}

	//DFS
	bool fourPuyo = false; //�ѿ䰡 4�� �̻� �������� �ִ���
	bool gravity = false; //�߷��� ��������� �ִ���

	while (true) {

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (grid[i][j] != '.') DFS(i, j);

				visited.assign(12, vector<bool>(6, false)); //�湮���� �ʱ�ȭ

				if (puyo >= 4) { //�ѿ䰡 4�� �̻��̶�� ��Ʈ����, ���� �ʱ�ȭ
					fourPuyo = true;
					puyo = 0;
					//���� �ѿ�� .�� ����
					while (!puyoLocation.empty()) {
						int x = puyoLocation.top().first;
						int y = puyoLocation.top().second;
						grid[x][y] = '.';
						puyoLocation.pop();


					}

				}
				puyo = 0;
			}
		}

		if (!fourPuyo && gravity) break; //�߷µ� ����� �� �����鼭 �ѿ� 4���� ���� ���� ���ٸ� ����

		if (fourPuyo) {
			result++;
			fourPuyo = false;
		}

		//�߷� ����
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				DFS_gravity(i, j);
				gravity = true;
			}
		}

	}


	cout << result;

}
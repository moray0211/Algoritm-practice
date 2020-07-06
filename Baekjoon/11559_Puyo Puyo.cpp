#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<vector<char>> grid; //grid[층][번호]
vector<vector<bool>> visited;
int result = 0; //연쇄 횟수. 한번에 여러 뿌요들이 터져도 연쇄는 한번으로 치는것에 주의.
int dx[4] = { 0, 1, 0 , -1 };
int dy[4] = { -1, 0, 1, 0 };
int puyo = 0; //뿌요의 수. 4개가 모여야 터진다
char color = '.'; //색상
stack<pair<int, int>> puyoLocation;

void DFS_gravity(int x, int y) {

	//X와 Y 위치 어디인지 확인하기. 행과 열 구분 주의...
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
		//색상 변경
		color = grid[x][y];
		//뿌요 수 증감
		puyo++;
		puyoLocation.push(make_pair(x, y)); //좌표 저장
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
	//칸은 6*12다.
	//빈공간 . 로 초기화
	grid.assign(12, vector<char>(6, '.'));
	visited.assign(12, vector<bool>(6, false));

	//한글자씩 잘라서 입력받기
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			char a;
			a = cin.get();
			grid[i][j] = a;
		}
		cin.get();
	}

	//DFS
	bool fourPuyo = false; //뿌요가 4개 이상 모인적이 있는지
	bool gravity = false; //중력이 적용된적이 있는지

	while (true) {

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (grid[i][j] != '.') DFS(i, j);

				visited.assign(12, vector<bool>(6, false)); //방문상태 초기화

				if (puyo >= 4) { //뿌요가 4개 이상이라면 터트리고, 갯수 초기화
					fourPuyo = true;
					puyo = 0;
					//터진 뿌요들 .로 변경
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

		if (!fourPuyo && gravity) break; //중력도 적용된 적 있으면서 뿌요 4개가 모일 수가 없다면 종료

		if (fourPuyo) {
			result++;
			fourPuyo = false;
		}

		//중력 적용
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				DFS_gravity(i, j);
				gravity = true;
			}
		}

	}


	cout << result;

}
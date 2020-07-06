#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> map;
vector<vector<bool>> visited;
vector<int> danji;
int dan = 0;
int N; //지도의 크기 N*N

void DFS(int x, int y) {
	visited[x][y] = true;

	if (x < N - 1 && !visited[x + 1][y] && map[x + 1][y]) { DFS(x + 1, y); }
	if (x > 0 && !visited[x - 1][y] && map[x - 1][y]) { DFS(x - 1, y); }
	if (y < N - 1 && !visited[x][y + 1] && map[x][y + 1]) { DFS(x, y + 1); }
	if (y > 0 && !visited[x][y - 1] && map[x][y - 1]) { DFS(x, y - 1); }
	dan++;

}

int main() {

	cin >> N;
	map.assign(N + 1, vector<bool>(N + 1, false));
	visited.assign(N + 1, vector<bool>(N + 1, false));
	danji.resize(N*N + 1);
	cin.get();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			a = cin.get() - '0';
			map[i][j] = a;
		}
		cin.get();
	}

	int n = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((!visited[i][j]) && map[i][j]) {
				dan = 0;
				DFS(i, j);
				danji[n++] = dan;
			}
		}
	}

	cout << n << endl;
	sort(danji.begin(), danji.begin() + n);
	for (int i = 0; i < n; i++) cout << danji[i] << endl;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue <int> q;
int num = 0;

//특정한 시작점으로부터 연결된 경로...그리고 묶음의 갯수를 알기 위함이므로 BFS 사용 (넓게 탐색)
//BFS는 노드 사이의 최단 경로 혹은 특정 경로를 찾고 싶을때 자주 사용됨
void BFS(int n, vector<vector<int>> computers) {
	vector<bool> discovered(n, false);

	//모든 컴퓨터 각각 조사
	for (int k = 0; k<n; k++) {

		//처음 발견했다면 네트워크 수 증감 후 큐에 추가.
		//어떠한 네트워크에 속한 컴퓨터는 아래 while문에서 발견할 수 있으므로, 발견되지 못했다면 새 네트워크에 포함됨을 의미.
		if (!discovered[k]) {
			num++;
			q.push(k);
			discovered[k] = true;
		}

		//큐가 빌때까지(현재 컴퓨터에 직간접적으로 연결된 컴퓨터를 모두 발견, 방문할때까지) 반복
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i<n; i++) {
				if (computers[here][i] == 1 && !discovered[i]) {
					discovered[i] = true;
					q.push(i);
				}
			}
		}
	}

}

//컴퓨터의 갯수 n, 연결정보가 저장된 computers
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	BFS(n, computers);
	answer = num;

	return answer;
}
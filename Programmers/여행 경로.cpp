#include <string>
#include <vector>
#include <algorithm>

//���� ������ �ణ �ָ��� ���� ����.

using namespace std;
vector<string> answer;
vector<bool> visited;
bool success = false;
int cnt = 0;

void DFS(vector<vector<string>>tickets, int from, int cnt, vector<string> &city) {

	city.push_back(tickets[from][0]);
	if (cnt == tickets.size()) {
		city.push_back(tickets[from][1]);
		answer = city;
		success = true;
		return;
	}
	visited[from] = true; //�湮

	for (int i = 0; i<tickets.size(); i++) {
		if (tickets[from][1].compare(tickets[i][0]) == 0 && !visited[i]) {
			DFS(tickets, i, cnt + 1, city);
			if (success) return;
			//��� �װ����� ����� �� ���ٸ� ��� ��ȸ
			city.pop_back();
			visited[i] = false;
		}
	}
	answer = city;
}

vector<string> solution(vector<vector<string>> tickets) {

	sort(tickets.begin(), tickets.end()); //���ĺ� ������ ���� (ASCII���� ���ĺ� �������� �����۴�)

	vector<string> city;

	for (int i = 0; i<tickets.size(); i++) {
		if (tickets[i][0].compare("ICN") == 0) {
			city.clear();
			visited.assign(tickets.size(), false);
			DFS(tickets, i, 1, city);
			if (success) break;
		}
	}
	return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;
//map<key, value>, unordered_map<key, value> ���ڴ� ����Ʈ�� ���ڴ� �ؽ� ���̺��̴�.
//�����Ͱ� �������� unordered_map�� �����ϴ�. ���ٸ� map�� ����.

string solution(vector<string> participant, vector<string> completion) {

	unordered_map<string, int> myMap;

	for (string name : participant) {
		myMap[name]++;
		//unordered_map[key] = value ������ ���� ����!
	}
	for (string name : completion) {
		myMap[name]--;
	}
	for (pair<string, int> p : myMap) {
		if (p.second > 0) return p.first;
	}

}
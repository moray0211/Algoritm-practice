#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;
//map<key, value>, unordered_map<key, value> 전자는 균형트리 후자는 해시 테이블이다.
//데이터가 적을수록 unordered_map이 유리하다. 많다면 map이 유리.

string solution(vector<string> participant, vector<string> completion) {

	unordered_map<string, int> myMap;

	for (string name : participant) {
		myMap[name]++;
		//unordered_map[key] = value 식으로 저장 가능!
	}
	for (string name : completion) {
		myMap[name]--;
	}
	for (pair<string, int> p : myMap) {
		if (p.second > 0) return p.first;
	}

}
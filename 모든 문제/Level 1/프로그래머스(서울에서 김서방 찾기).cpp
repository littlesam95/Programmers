#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
string answer = "";
int index;

string solution(vector<string> seoul) {
	for (int i = 0; i < seoul.size(); i++) {
		if (seoul[i] == "Kim") {
			index = i;
			break;
		}
	}

	answer += "�輭���� " + to_string(index) + "�� �ִ�";

	return answer;
}
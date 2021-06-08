#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
string answer = "";

string solution(string s) {
	int len = s.length();
	if (len % 2 == 0) {
		int index = len / 2;
		answer += s.substr(index - 1, 2);
	}
	else if (len % 2 == 1) {
		int index = len / 2;
		answer += s.substr(index, 1);
	}

	return answer;
}
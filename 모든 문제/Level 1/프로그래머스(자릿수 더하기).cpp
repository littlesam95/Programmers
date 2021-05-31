#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int answer = 0;

int solution(int n) {
	string str = to_string(n);
	for (int i = 0; i < str.length(); i++) {
		answer += stoi(str.substr(i, 1));
	}

	return answer;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int answer = 0;
int b = 0;

int solution(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			if (s.substr(i, 1) == "+") {
				b = 1;
			}
			else if (s.substr(i, 1) == "-") {
				b = 2;
			}
			else {
				b = 3;
			}
			if (b == 3) {
				answer = stoi(s);
				break;
			}
		}
		else {
			if ((b == 1) || (b == 2)) {
				answer = stoi(s.substr(1));
				if (b == 2) {
					answer -= (answer * 2);
				}
			}
		}
	}
	return answer;
}
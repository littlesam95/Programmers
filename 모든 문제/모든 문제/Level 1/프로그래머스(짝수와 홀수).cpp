#include <iostream>
#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(int num) {
	if (abs(num) % 2 == 0) {
		answer += "Even";
	}
	else if (abs(num) % 2 == 1) {
		answer += "Odd";
	}
	return answer;
}
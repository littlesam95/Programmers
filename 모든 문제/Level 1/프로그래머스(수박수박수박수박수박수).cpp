#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
string answer = "";

string solution(int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			answer += "¼ö";
		}
		else if (i % 2 == 1) {
			answer += "¹Ú";
		}
	}
	return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

string solution(string number, int k) {
	int numSize = number.size() - k;
	int start = 0;
	for (int i = 0; i < numSize; i++) {
		char nowNum = number[start];
		int index = start;
		for (int j = start; j <= k + i; j++) {
			if (nowNum < number[j]) {
				nowNum = number[j];
				index = j;
			}
		}
		start = index + 1;
		answer += nowNum;
	}

	return answer;
}
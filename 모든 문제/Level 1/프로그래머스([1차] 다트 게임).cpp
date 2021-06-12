#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(string dartResult) {
	string tmp = "";
	int score[1001];
	int index = 0;
	for (int i = 0; i < dartResult.size(); i++) {
		if ((dartResult[i] >= 48) && (dartResult[i] <= 57)) {
			tmp += dartResult[i];
		}
		else if (dartResult[i] == 'S') {
			score[index] = pow(stoi(tmp), 1);
			index++;
			tmp = "";
		}
		else if (dartResult[i] == 'D') {
			score[index] = pow(stoi(tmp), 2);
			index++;
			tmp = "";
		}
		else if (dartResult[i] == 'T') {
			score[index] = pow(stoi(tmp), 3);
			index++;
			tmp = "";
		}
		else if (dartResult[i] == '*') {
			score[index - 1] *= 2;
			score[index - 2] *= 2;
		}
		else if (dartResult[i] == '#') {
			score[index - 1] *= -1;
		}
	}
	for (int i = 0; i < index; i++) {
		answer += score[i];
	}

	return answer;
}
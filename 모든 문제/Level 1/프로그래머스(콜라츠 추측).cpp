#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int num) {
	while (num != 1) {
		if (num % 2 == 0) {
			num /= 2;
		}
		else if (num % 2 == 1) {
			num *= 3;
			num += 1;
		}
		answer++;
		if (answer == 500) {
			answer = -1;
			break;
		}
	};
	return answer;
}
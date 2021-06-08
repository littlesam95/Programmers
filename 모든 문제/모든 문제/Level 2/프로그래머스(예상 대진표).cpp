#include <iostream>
#include <algorithm>

using namespace std;
int answer = 1;

int solution(int n, int a, int b) {
	bool c;
	if (a < b) {
		c = true;
	}
	else {
		c = false;
	}
	while (1) {
		if (c) {
			if ((a % 2 == 1) && (b % 2 == 0) && (b - a == 1)) {
				break;
			}
		}
		else if (!c) {
			if ((a % 2 == 0) && (b % 2 == 1) && (a - b == 1)) {
				break;
			}
		}

		answer++;
		if (a % 2 == 0) {
			a /= 2;
		}
		else if (a % 2 == 1) {
			a /= 2;
			a += 1;
		}
		if (b % 2 == 0) {
			b /= 2;
		}
		else if (b % 2 == 1) {
			b /= 2;
			b += 1;
		}
	};

	return answer;
}
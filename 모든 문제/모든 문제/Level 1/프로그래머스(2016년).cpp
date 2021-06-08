#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
string answer = "";
string arr[367];

void init() {
	for (int i = 1; i < 367; i++) {
		if (i % 7 == 0) {
			arr[i] = "THU";
		}
		if (i % 7 == 1) {
			arr[i] = "FRI";
		}
		if (i % 7 == 2) {
			arr[i] = "SAT";
		}
		if (i % 7 == 3) {
			arr[i] = "SUN";
		}
		if (i % 7 == 4) {
			arr[i] = "MON";
		}
		if (i % 7 == 5) {
			arr[i] = "TUE";
		}
		if (i % 7 == 6) {
			arr[i] = "WED";
		}
	}
}

string solution(int a, int b) {
	init();
	if (a == 1) {
		answer = arr[b];
	}
	else if (a == 2) {
		answer = arr[b + 31];
	}
	else if (a == 3) {
		answer = arr[b + 60];
	}
	else if (a == 4) {
		answer = arr[b + 91];
	}
	else if (a == 5) {
		answer = arr[b + 121];
	}
	else if (a == 6) {
		answer = arr[b + 152];
	}
	else if (a == 7) {
		answer = arr[b + 182];
	}
	else if (a == 8) {
		answer = arr[b + 213];
	}
	else if (a == 9) {
		answer = arr[b + 244];
	}
	else if (a == 10) {
		answer = arr[b + 274];
	}
	else if (a == 11) {
		answer = arr[b + 305];
	}
	else if (a == 12) {
		answer = arr[b + 335];
	}
	return answer;
}
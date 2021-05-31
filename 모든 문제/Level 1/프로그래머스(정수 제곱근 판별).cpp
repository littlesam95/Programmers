#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
long long answer = 0;

long long solution(long long n) {
	if (sqrt(n) - (int)sqrt(n) == 0) {
		answer = (sqrt(n) + 1) * (sqrt(n) + 1);
	}
	else {
		answer = -1;
	}

	return answer;
}
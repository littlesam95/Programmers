#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int answer = 0;

int solution(int n) {
	string str = "";
	int k = pow(3, 16);
	while (k > 0) {
		int tmp = n / k;
		str += to_string(tmp);
		n -= (tmp * k);
		k /= 3;
	};

	int zero_cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str.substr(i, 1) == "0") {
			zero_cnt++;
		}
		else {
			break;
		}
	}

	string res = "";
	for (int i = zero_cnt; i < str.length(); i++) {
		res += str.substr(i, 1);
	}

	for (int i = 0; i < res.length(); i++) {
		answer += (stoi(res.substr(i, 1)) * pow(3, i));
	}

	return answer;
}
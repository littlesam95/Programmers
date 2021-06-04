#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

bool comp(string A, string B) {
	return A + B > B + A;
}

string solution(vector<int> numbers) {
	vector<string> numStr;
	string answer = "";
	bool zero = true;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] != 0) {
			zero = false;
		}
		numStr.push_back(to_string(numbers[i]));
	}
	if (!zero) {
		sort(numStr.begin(), numStr.end(), comp);
		for (int i = 0; i < numStr.size(); i++) {
			answer += numStr[i];
		}
	}
	else {
		answer = "0";
	}
	return answer;
}
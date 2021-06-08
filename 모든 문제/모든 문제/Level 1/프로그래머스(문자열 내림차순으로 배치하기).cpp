#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
string answer = "";
vector<char> vec;

string solution(string s) {
	for (int i = 0; i < s.size(); i++) {
		vec.push_back(s[i]);
	}
	sort(vec.begin(), vec.end(), greater<char>());
	for (int i = 0; i < vec.size(); i++) {
		answer += vec[i];
	}

	return answer;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
long long answer = 0;
vector<int> vec;

long long solution(long long n) {
	string str = to_string(n);
	for (int i = 0; i < str.length(); i++) {
		vec.push_back(stoi(str.substr(i, 1)));
	}
	sort(vec.begin(), vec.end());

	int index = 1;
	for (int i = 0; i < vec.size(); i++) {
		answer += (vec[i] * index);
		index *= 10;
	}
	return answer;
}
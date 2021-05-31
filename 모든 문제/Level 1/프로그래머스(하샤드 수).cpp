#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool answer = true;

bool solution(int x) {
	string str = to_string(x);
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		sum += stoi(str.substr(i, 1));
	}
	answer = (x % sum == 0);

	return answer;
}
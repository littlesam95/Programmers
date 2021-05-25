#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
string res = "";

string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < participant.size(); i++) {
		if (participant[i] != completion[i]) {
			res = participant[i];
			break;
		}
	}

	return res;
}
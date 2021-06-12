#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

vector<string> split(string s) {
	vector<string> res;
	string tmp = "";
	int idx = 0;
	while (idx <= s.size()) {
		if ((s[idx] == ' ') || (idx == s.size())) {
			res.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += s[idx];
		}
		idx++;
	};
	return res;
}

string solution(string s) {
	vector<string> vec = split(s);
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (j % 2 == 0) {
				if (islower(vec[i][j])) {
					vec[i][j] = toupper(vec[i][j]);
				}
			}
			else if (j % 2 == 1) {
				if (isupper(vec[i][j])) {
					vec[i][j] = tolower(vec[i][j]);
				}
			}
		}
		if (i < vec.size() - 1) {
			answer += (vec[i] + " ");
		}
		else if (i == vec.size() - 1) {
			answer += vec[i];
		}
	}

	return answer;
}
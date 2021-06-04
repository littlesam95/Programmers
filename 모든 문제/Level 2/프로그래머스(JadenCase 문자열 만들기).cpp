#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
string answer = "";

vector<string> change(string s) {
	vector<string> vec;
	int index = 0;
	string tmp = "";
	while (index < s.length()) {
		if (index < s.length() - 1) {
			if (s[index] == ' ') {
				for (int i = 0; i < tmp.size(); i++) {
					if (i == 0) {
						if (islower(tmp[i])) {
							tmp[i] = toupper(tmp[i]);
						}
					}
					else if (i > 0) {
						if (isupper(tmp[i])) {
							tmp[i] = tolower(tmp[i]);
						}
					}
				}
				vec.push_back(tmp);
				tmp = "";
				index++;
			}
			else {
				tmp += s[index];
				index++;
			}
		}
		else if (index == s.length() - 1) {
			tmp += s[index];
			for (int i = 0; i < tmp.size(); i++) {
				if (i == 0) {
					if (islower(tmp[i])) {
						tmp[i] = toupper(tmp[i]);
					}
				}
				else if (i > 0) {
					if (isupper(tmp[i])) {
						tmp[i] = tolower(tmp[i]);
					}
				}
			}
			vec.push_back(tmp);
			tmp = "";
			index++;
		}
	};
	return vec;
}

string solution(string s) {
	vector<string> vec = change(s);
	for (int i = 0; i < vec.size(); i++) {
		answer += vec[i];
		if (i < vec.size() - 1) {
			answer += " ";
		}
	}
	return answer;
}
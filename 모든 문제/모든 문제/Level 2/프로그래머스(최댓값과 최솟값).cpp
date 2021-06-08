#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

vector<int> change(string s) {
	vector<int> vec;
	string tmp = "";
	int index = 0;
	while (index < s.length()) {
		if (index < s.length() - 1) {
			if (s.substr(index, 1) == " ") {
				vec.push_back(stoi(tmp));
				index++;
				tmp = "";
			}
			else {
				tmp += s.substr(index, 1);
				index++;
			}
		}
		else if (index == s.length() - 1) {
			tmp += s.substr(index, 1);
			vec.push_back(stoi(tmp));
			index++;
		}
	};

	return vec;
}

string solution(string s) {
	vector<int> vec = change(s);
	sort(vec.begin(), vec.end());
	int size = vec.size();
	answer += to_string(vec[0]);
	answer += " ";
	answer += to_string(vec[size - 1]);

	return answer;
}
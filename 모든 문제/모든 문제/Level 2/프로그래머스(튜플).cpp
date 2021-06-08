#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;

bool comp(vector<int> A, vector<int> B) {
	return A.size() < B.size();
}

vector<int> solution(string s) {
	int len = s.length();
	string newS = s.substr(1, len - 2);
	vector<vector<int> > vec;
	int index = 0;
	vector<int> tmp;
	string tm = "";
	while (index < newS.length()) {
		if (newS.substr(index, 1) == ",") {
			if (newS.substr(index + 1, 1) == "{") {
				index++;
				continue;
			}
			else {
				tmp.push_back(stoi(tm));
				tm = "";
			}
		}
		else if ((int(newS[index]) >= 48) && (int(newS[index]) <= 57)) {
			tm += newS.substr(index, 1);
		}
		else if (newS.substr(index, 1) == "}") {
			tmp.push_back(stoi(tm));
			tm = "";
			vec.push_back(tmp);
			tmp.clear();
		}
		index++;
	};
	sort(vec.begin(), vec.end(), comp);
	answer.push_back(vec[0][0]);
	for (int i = 1; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			bool b = false;
			for (int k = 0; k < answer.size(); k++) {
				if (vec[i][j] == answer[k]) {
					b = true;
					break;
				}
			}
			if (!b) {
				answer.push_back(vec[i][j]);
				break;
			}
		}
	}
	return answer;
}
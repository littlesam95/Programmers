#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int answer = 0;

bool comp(string A, string B) {
	if (A.size() < B.size()) {
		return true;
	}
	else if (A.size() > B.size()) {
		return false;
	}
	else {
		return (A < B);
	}
}

int solution(vector<vector<string>> relation) {
	vector<int> attribute;
	for (int i = 0; i < relation[0].size(); i++) {
		attribute.push_back(i);
	}
	vector<string> can_key;
	do {
		string tmp = "";
		for (int i = 0; i < attribute.size(); i++) {
			tmp += to_string(attribute[i]);
			can_key.push_back(tmp);
		}
	} while (next_permutation(attribute.begin(), attribute.end()));
	for (int i = 0; i < can_key.size(); i++) {
		sort(can_key[i].begin(), can_key[i].end());
	}
	sort(can_key.begin(), can_key.end(), comp);
	can_key.erase(unique(can_key.begin(), can_key.end()), can_key.end());

	unordered_map<string, int> m;
	for (int i = 0; i < can_key.size(); i++) {
		m.insert(make_pair(can_key[i], 1));
	}

	vector<string> ans_vec;
	for (int i = 0; i < can_key.size(); i++) {
		if (m[can_key[i]] == 1) {
			vector<string> entire;
			for (int j = 0; j < relation.size(); j++) {
				string tmp = "";
				for (int k = 0; k < can_key[i].size(); k++) {
					tmp += relation[j][stoi(can_key[i].substr(k, 1))];
				}
				entire.push_back(tmp);
			}
			bool b = true;
			for (int j = 0; j < entire.size(); j++) {
				for (int k = j + 1; k < entire.size(); k++) {
					if (entire[j] == entire[k]) {
						b = false;
						break;
					}
				}
				if (!b) {
					break;
				}
			}
			if (b) {
				ans_vec.push_back(can_key[i]);
				m[can_key[i]]++;
				for (auto it = m.begin(); it != m.end(); it++) {
					bool c = true;
					if (it->second == 1) {
						for (int j = 0; j < can_key[i].size(); j++) {
							if (it->first.find(can_key[i].substr(j, 1)) == string::npos) {
								c = false;
								break;
							}
						}
						if (c) {
							it->second--;
						}
					}
				}

			}
			else continue;
		}
	}
	answer = ans_vec.size();
	return answer;
}
#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(string skill, vector<string> skill_trees) {
	for (int i = 0; i < skill_trees.size(); i++) {
		string tmp = "";
		for (int j = 0; j < skill_trees[i].length(); j++) {
			bool b = false;
			for (int k = 0; k < skill.length(); k++) {
				if (skill_trees[i].substr(j, 1) == skill.substr(k, 1)) {
					b = true;
					break;
				}
			}
			if (b) {
				tmp += skill_trees[i].substr(j, 1);
			}
		}
		bool c = true;
		for (int j = 0; j < tmp.length(); j++) {
			if (tmp[j] != skill[j]) {
				c = false;
				break;
			}
		}
		if (c) {
			answer++;
		}
	}
	return answer;
}
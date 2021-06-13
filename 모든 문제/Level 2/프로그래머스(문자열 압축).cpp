#include <string>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
int answer = INT_MAX;

int solution(string s) {
	int last_size = s.size() / 2;
	if (last_size < 1) {
		last_size = 1;
	}
	for (int i = 1; i <= last_size; i++) {
		string tmp_s = s;
		string newS = "";
		vector<string> vec;
		int idx = 1;
		string tmp = "";
		while (idx <= tmp_s.size()) {
			tmp += tmp_s[idx - 1];
			if ((idx % i == 0) || (idx == tmp_s.size())) {
				vec.push_back(tmp);
				tmp = "";
			}
			idx++;
		};
		for (int i = 0; i < vec.size(); i++) {
			int num = 1;
			for (int j = i + 1; j < vec.size(); j++) {
				if (vec[i] == vec[j]) {
					num++;
					vec.erase(vec.begin() + j);
					j--;
				}
				else {
					break;
				}
			}
			if (num >= 2) {
				string vec_tmp = to_string(num) + vec[i];
				vec[i] = vec_tmp;
			}
			newS += vec[i];
		}
		int size = newS.size();
		answer = min(answer, size);
	}

	return answer;
}
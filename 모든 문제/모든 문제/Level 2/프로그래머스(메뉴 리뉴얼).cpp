#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<string> answer;
unordered_map<string, int> m;
vector<string> menu[27][21];
int cnt[27];

void calc(string s, int idx, string made) {
	if (made.size() > 1) {
		m[made]++;
		cnt[made.size()] = max(cnt[made.size()], m[made]);
		menu[made.size()][m[made]].push_back(made);
	}

	for (int i = idx + 1; i < s.size(); i++) {
		made.push_back(s[i]);
		calc(s, i, made);
		made.pop_back();
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	for (string& s : orders) {
		sort(s.begin(), s.end());
		calc(s, -1, "");
	}

	for (int i : course) {
		if (cnt[i] > 1) {
			for (string s : menu[i][cnt[i]]) {
				answer.push_back(s);
			}
		}
	}
	sort(answer.begin(), answer.end());

	return answer;
}

// 나중에 다시 풀어보기
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> answer;

bool comp1(pair<string, int> A, pair<string, int> B) {
	return (A.second > B.second);
}

bool comp2(pair<int, int> A, pair<int, int> B) {
	if (A.second > B.second) {
		return true;
	}
	else if (A.second == B.second) {
		return (A.first < B.first);
	}
	else {
		return false;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> gpm;
	for (int i = 0; i < genres.size(); i++) {
		if (gpm.find(genres[i]) == gpm.end()) {
			gpm.insert(make_pair(genres[i], plays[i]));
		}
		else {
			gpm[genres[i]] += plays[i];
		}
	}
	vector<pair<string, int> > vec(gpm.begin(), gpm.end());
	sort(vec.begin(), vec.end(), comp1);

	for (int i = 0; i < vec.size(); i++) {
		unordered_map<int, int> spm;
		for (int j = 0; j < plays.size(); j++) {
			if (vec[i].first == genres[j]) {
				spm.insert(make_pair(j, plays[j]));
			}
		}
		vector<pair<int, int> > vec2(spm.begin(), spm.end());
		sort(vec2.begin(), vec2.end(), comp2);
		if (vec2.size() == 1) {
			answer.push_back(vec2[0].first);
		}
		else if (vec2.size() >= 2) {
			answer.push_back(vec2[0].first);
			answer.push_back(vec2[1].first);
		}
	}


	return answer;
}
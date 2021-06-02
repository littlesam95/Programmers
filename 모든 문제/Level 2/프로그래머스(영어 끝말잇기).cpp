#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
vector<int> answer;
unordered_set<string> s;

vector<int> solution(int n, vector<string> words) {
	int index = 0;
	int count = 1;
	bool b = true;
	for (int i = 0; i < words.size(); i++) {
		if (i == 0) {
			s.insert(words[i]);
			index++;
		}
		else if (i > 0) {
			s.insert(words[i]);
			index++;
			if (words[i - 1].substr(words[i - 1].length() - 1) != words[i].substr(0, 1)) {
				answer.push_back(index);
				answer.push_back(count);
				b = false;
				break;
			}
			else {
				if (s.size() != i + 1) {
					answer.push_back(index);
					answer.push_back(count);
					b = false;
					break;
				}
			}
			if (index == n) {
				index = 0;
				count++;
			}
		}
	}

	if ((s.size() == (n * (count - 1))) && b) {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}
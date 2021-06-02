#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(string s) {
	for (int i = 0; i < s.length(); i++) {
		s += s[0];
		string tmp = s.substr(1);
		s = tmp;
		stack<int> st;
		bool b = true;
		int index = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') {
				st.push(0);
				index++;
			}
			else if (s[j] == '{') {
				st.push(1);
				index++;
			}
			else if (s[j] == '[') {
				st.push(2);
				index++;
			}
			else if (s[j] == ')') {
				if (!st.empty()) {
					if (st.top() != 0) {
						b = false;
						break;
					}
					else {
						st.pop();
						index--;
					}
				}
				else {
					b = false;
					break;
				}
			}
			else if (s[j] == '}') {
				if (!st.empty()) {
					if (st.top() != 1) {
						b = false;
						break;
					}
					else {
						st.pop();
						index--;
					}
				}
				else {
					b = false;
					break;
				}
			}
			else if (s[j] == ']') {
				if (!st.empty()) {
					if (st.top() != 2) {
						b = false;
						break;
					}
					else {
						st.pop();
						index--;
					}
				}
				else {
					b = false;
					break;
				}
			}
		}
		if (b && (index == 0)) {
			answer++;
		}
	}

	return answer;
}
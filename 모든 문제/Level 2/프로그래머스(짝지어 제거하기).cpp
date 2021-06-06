#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(string s) {
	stack<char> st;
	int index = 0;
	char st_top;
	while (1) {
		if (st.empty()) {
			st.push(s[index]);
			st_top = st.top();
		}
		else {
			st.push(s[index]);
			if (st_top == st.top()) {
				st.pop();
				st.pop();
			}
			if (!st.empty()) {
				st_top = st.top();
			}
		}
		index++;
		if (index == s.size()) break;
	};

	if (st.empty()) {
		answer = 1;
	}

	return answer;
}
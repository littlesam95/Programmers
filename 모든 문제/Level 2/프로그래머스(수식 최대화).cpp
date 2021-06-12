#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long answer = 0;
vector<char> op_order = { '*', '+', '-' };

long long calc(long long A, long long B, char op) {
	if (op == '+') {
		return A + B;
	}
	else if (op == '-') {
		return A - B;
	}
	else {
		return A * B;
	}
}

long long solution(string expression) {
	vector<long long> ll_vec;
	vector<char> op_vec;
	int idx = 0;
	string tmp = "";
	while (idx <= expression.size()) {
		if ((expression[idx] == '*') || (expression[idx] == '+') || (expression[idx] == '-')) {
			ll_vec.push_back(stoll(tmp));
			op_vec.push_back(expression[idx]);
			tmp = "";
		}
		else if (idx == expression.size()) {
			ll_vec.push_back(stoll(tmp));
			tmp = "";
		}
		else {
			tmp += expression[idx];
		}
		idx++;
	};

	do {
		vector<long long> ll_vec_tmp = ll_vec;
		vector<char> op_vec_tmp = op_vec;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < op_vec_tmp.size(); j++) {
				if (op_order[i] == op_vec_tmp[j]) {
					ll_vec_tmp[j] = calc(ll_vec_tmp[j], ll_vec_tmp[j + 1], op_vec_tmp[j]);
					ll_vec_tmp.erase(ll_vec_tmp.begin() + j + 1);
					op_vec_tmp.erase(op_vec_tmp.begin() + j);
					j--;
				}
			}
		}
		answer = max(answer, abs(ll_vec_tmp[0]));
	} while (next_permutation(op_order.begin(), op_order.end()));

	return answer;
}
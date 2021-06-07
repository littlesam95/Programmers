#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

string solution(int n) {
	int remain = 0;
	int res = n;

	while (res > 0) {
		remain = res % 3;
		res /= 3;

		if (remain == 0) {
			answer = "4" + answer;
			res--;
		}
		else if (remain == 1) {
			answer = "1" + answer;
		}
		else if (remain == 2) {
			answer = "2" + answer;
		}
	};
	return answer;
}
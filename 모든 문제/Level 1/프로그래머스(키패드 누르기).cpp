#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

string solution(vector<int> numbers, string hand) {
	int leftY = 3;
	int leftX = 0;
	int rightY = 3;
	int rightX = 2;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1) {
			leftY = 0;
			leftX = 0;
			answer += "L";
		}
		else if (numbers[i] == 4) {
			leftY = 1;
			leftX = 0;
			answer += "L";
		}
		else if (numbers[i] == 7) {
			leftY = 2;
			leftX = 0;
			answer += "L";
		}
		else if (numbers[i] == 3) {
			rightY = 0;
			rightX = 2;
			answer += "R";
		}
		else if (numbers[i] == 6) {
			rightY = 1;
			rightX = 2;
			answer += "R";
		}
		else if (numbers[i] == 9) {
			rightY = 2;
			rightX = 2;
			answer += "R";
		}
		else if (numbers[i] == 2) {
			int left_len = abs(leftY - 0) + abs(leftX - 1);
			int right_len = abs(rightY - 0) + abs(rightX - 1);
			if (left_len < right_len) {
				leftY = 0;
				leftX = 1;
				answer += "L";
			}
			else if (left_len > right_len) {
				rightY = 0;
				rightX = 1;
				answer += "R";
			}
			else if (left_len == right_len) {
				if (hand == "right") {
					rightY = 0;
					rightX = 1;
					answer += "R";
				}
				else if (hand == "left") {
					leftY = 0;
					leftX = 1;
					answer += "L";
				}
			}
		}
		else if (numbers[i] == 5) {
			int left_len = abs(leftY - 1) + abs(leftX - 1);
			int right_len = abs(rightY - 1) + abs(rightX - 1);
			if (left_len < right_len) {
				leftY = 1;
				leftX = 1;
				answer += "L";
			}
			else if (left_len > right_len) {
				rightY = 1;
				rightX = 1;
				answer += "R";
			}
			else if (left_len == right_len) {
				if (hand == "right") {
					rightY = 1;
					rightX = 1;
					answer += "R";
				}
				else if (hand == "left") {
					leftY = 1;
					leftX = 1;
					answer += "L";
				}
			}
		}
		else if (numbers[i] == 8) {
			int left_len = abs(leftY - 2) + abs(leftX - 1);
			int right_len = abs(rightY - 2) + abs(rightX - 1);
			if (left_len < right_len) {
				leftY = 2;
				leftX = 1;
				answer += "L";
			}
			else if (left_len > right_len) {
				rightY = 2;
				rightX = 1;
				answer += "R";
			}
			else if (left_len == right_len) {
				if (hand == "right") {
					rightY = 2;
					rightX = 1;
					answer += "R";
				}
				else if (hand == "left") {
					leftY = 2;
					leftX = 1;
					answer += "L";
				}
			}
		}
		else if (numbers[i] == 0) {
			int left_len = abs(leftY - 3) + abs(leftX - 1);
			int right_len = abs(rightY - 3) + abs(rightX - 1);
			if (left_len < right_len) {
				leftY = 3;
				leftX = 1;
				answer += "L";
			}
			else if (left_len > right_len) {
				rightY = 3;
				rightX = 1;
				answer += "R";
			}
			else if (left_len == right_len) {
				if (hand == "right") {
					rightY = 3;
					rightX = 1;
					answer += "R";
				}
				else if (hand == "left") {
					leftY = 3;
					leftX = 1;
					answer += "L";
				}
			}
		}
	}

	return answer;
}
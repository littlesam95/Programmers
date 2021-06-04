#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;

vector<int> solution(int brown, int yellow) {
	for (int w = 1; w < (brown - 4) / 2; w++) {
		int h = ((brown - 4) / 2) - w;
		if (yellow == (w * h)) {
			answer.push_back(h + 2);
			answer.push_back(w + 2);
			break;
		}
		else continue;
	}
	return answer;
}
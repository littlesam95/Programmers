#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
vector<int> res;

vector<int> solution(vector<int> arr, vector<vector<int> > commands) {
	for (int i = 0; i < commands.size(); i++) {
		vector<int> newArr;
		for (int a = commands[i][0] - 1; a <= commands[i][1] - 1; a++) {
			newArr.push_back(arr[a]);
		}
		sort(newArr.begin(), newArr.end());
		res.push_back(newArr[commands[i][2] - 1]);
	}

	return res;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int arr[501] = { 0, };
vector<int> answer;
vector<int> countP;
vector<pair<double, int> > vec;

bool comp(pair<double, int> A, pair<double, int> B) {
	if (A.first > B.first) {
		return true;
	}
	else if (A.first == B.first) {
		if (A.second < B.second) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

vector<int> solution(int N, vector<int> stages) {
	for (int i = 0; i < stages.size(); i++) {
		arr[stages[i]]++;
	}

	int size = stages.size();
	for (int i = 1; i <= N; i++) {
		double tmp = (double)arr[i] / (double)size;
		if (arr[i] == 0) {
			tmp = 0;
		}
		size -= arr[i];
		vec.push_back(make_pair(tmp, i));
	}

	sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < vec.size(); i++) {
		answer.push_back(vec[i].second);
	}


	return answer;
}
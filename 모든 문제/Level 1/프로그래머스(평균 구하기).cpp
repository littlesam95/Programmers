#include <iostream>
#include <string>
#include <vector>

using namespace std;
double answer = 0;

double solution(vector<int> arr) {
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	answer = (double)sum / (double)arr.size();
	return answer;
}
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
deque<int> index;
deque<int> printPriorities;
unordered_map<int, int> m;
int priority = 9;
int priorityArr[10] = { 0, };
int countOrder = 1;

int solution(vector<int> priorities, int location) {
	for (int i = 0; i < priorities.size(); i++) {
		index.push_back(i);
		printPriorities.push_back(priorities[i]);
		priorityArr[priorities[i]]++;
	}

	while (priority > 0) {
		if (priorityArr[priority] == 0) {
			priority--;
		}
		else if (priorityArr[priority] > 0) {
			int size = index.size();
			for (int i = 0; i < size; i++) {
				if (priority == printPriorities.front()) {
					m.insert(make_pair(index.front(), countOrder));
					index.pop_front();
					printPriorities.pop_front();
					countOrder++;
					priorityArr[priority]--;
					if (priorityArr[priority] == 0) {
						break;
					}
				}
				else if (priority > printPriorities.front()) {
					index.push_back(index.front());
					printPriorities.push_back(printPriorities.front());
					index.pop_front();
					printPriorities.pop_front();
				}
			}
			priority--;
		}
	};

	int res = m[location];
	return res;
}
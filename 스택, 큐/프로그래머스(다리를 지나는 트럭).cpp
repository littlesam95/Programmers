#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
queue<pair<int, int> > ride;
int depart = 0;
int countTime = 0;
int truckIndex = 0;
int weightSum = 0;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	while (depart < truck_weights.size()) {
		if (ride.front().second == bridge_length) {
			depart++;
			weightSum -= ride.front().first;
			ride.pop();
		}
		if (truckIndex < truck_weights.size()) {
			if ((weightSum + truck_weights[truckIndex] <= weight)) {
				ride.push(make_pair(truck_weights[truckIndex], 0));
				weightSum += truck_weights[truckIndex];
				truckIndex++;
			}
		}
		int rideSize = ride.size();
		for (int i = 0; i < rideSize; i++) {
			ride.push(make_pair(ride.front().first, ride.front().second + 1));
			ride.pop();
		}
		countTime++;
	};

	int answer = countTime;
	return answer;
}
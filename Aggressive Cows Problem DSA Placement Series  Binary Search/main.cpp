#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int n, int c, int minAllowedDistance) {
	int cows = 1;
	int lastStallPosition = arr[0];
	for (int a = 1; a < n; a++) {
		if (arr[a] - lastStallPosition >= minAllowedDistance) {
			cows++;
			lastStallPosition = arr[a];
		}
		if (cows == c) {
			return true;
		}
	}
	return false;
}

int getDistance(vector<int>& arr, int n, int c) {
	sort(arr.begin(), arr.end());
	int minVal = arr[0];
	int maxVal = arr[n - 1];
	int start = 1;
	int end = maxVal - minVal;
	int answer = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (isPossible(arr, n, c, mid)) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return answer;
}
int main() {
	int n = 5;
	int c = 3;
	vector<int> arr = { 1, 2, 8, 4, 9 };
	cout << getDistance(arr, n, c) << endl;
	return 0;
}
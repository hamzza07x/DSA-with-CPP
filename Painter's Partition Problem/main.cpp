#include<iostream>
#include<vector>
using namespace std;

int isPossible(vector<int>& arr, int n, int m, int maxAllowedTime) {
	int painter = 1;
	int time = 0;
	for (int a = 0; a < n; a++) {
		if (time + arr[a] <= maxAllowedTime) {
			time = time + arr[a];
		}
		else {
			painter = painter + 1;
			time = arr[a];
		}
	}
	return painter <= m;
}

int minTimeToPaint(vector<int>& arr, int n, int m) {
	int sum = 0;
	int maxVal = INT16_MIN;
	for (int a = 0; a < n; a++) {
		sum = sum + arr[a];
		maxVal = max(maxVal, arr[a]);
	}
	int start = maxVal;
	int end = sum;
	int answer = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (isPossible(arr, n, m, mid)) {
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return answer;
}

int main() {
	vector<int> arr = { 10, 20, 30, 40 };
	int n = 4;
	int m = 2;
	cout << minTimeToPaint(arr, n, m);
	return 0;
}
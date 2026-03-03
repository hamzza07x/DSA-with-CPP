#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int students = 1;
    int pages = 0;

    for (int a = 0; a < n; a++) {
        if (arr[a] > maxAllowedPages) {
            return false;
        }

        if (pages + arr[a] <= maxAllowedPages) {
            pages += arr[a];
        }
        else {
            students++;
            pages = arr[a];
        }
    }

    return students <= m;
}

int allocateBooks(vector<int>& arr, int n, int m) {
    int sum = 0;
    for (int a = 0; a < n; a++) {
        sum += arr[a];
    }

    int start = 0;
    int end = sum;
    int answer = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isvalid(arr, n, m, mid)) {
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
    vector<int> arr = { 2, 1, 3, 4 };
    int n = arr.size();
    int m = 2;

    int ans = allocateBooks(arr, n, m);
    cout << ans << endl;

    return 0;
}
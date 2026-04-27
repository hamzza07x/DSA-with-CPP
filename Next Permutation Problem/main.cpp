#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();

        // Step 1: find pivot
        for (int a = n - 2; a >= 0; a--) {
            if (nums[a] < nums[a + 1]) {
                pivot = a;
                break;
            }
        }

        // Step 2: if no pivot, reverse whole array
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: find next greater element
        for (int a = n - 1; a > pivot; a--) {
            if (nums[a] > nums[pivot]) {
                swap(nums[a], nums[pivot]);
                break;
            }
        }

        // Step 4: reverse right side
        int i = pivot + 1;
        int j = n - 1;
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};

int main() {
    Solution S;
    vector<int> nums = { 1, 2, 3 };

    S.nextPermutation(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
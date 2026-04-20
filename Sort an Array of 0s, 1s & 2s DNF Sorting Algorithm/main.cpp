#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
				swap(nums[low], nums[mid]);
				mid = mid + 1;
				low = low + 1;
            }
            else if (nums[mid] == 1) {
				mid = mid + 1;
            }
			else {
				swap(nums[mid], nums[high]);
				high = high - 1;
            }
        }
    }
};

int main() {
    Solution S;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
     S.sortColors(nums);
     for (int i = 0; i < nums.size(); i++) {
         cout << nums[i] << " ";
     }
	 cout << endl;
	return 0;
}
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        int middle;

        while (left < right) {
            middle = left + (right - left) / 2;

            if (target < nums[middle]) {
                right = middle;
            } else if (target > nums[middle]) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        if (target <= nums[left]) {
            return left;
        } else {
            return left + 1;
        }
    }
};

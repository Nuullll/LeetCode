class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // find the rotate pivot first: O(n)
        // binary search each part: O(2log(n/2)) = O(log(n))
        // total complexity: O(n) + O(log(n))

        // further improvement
        // find the rotate pivot using binary search: O(log(n))
        // total complexity: O(log(n))
        // rule:
        // let i be the index of the pivot
        // then nums[i] >= nums[i+1] always holds
        // NNNNNNNNNNNNNNOOOOOOOOOOOO
        // duplicates make it (seem) at least O(n) to find pivot
        int n = nums.size();
        int pivot = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                pivot = i;
                break;
            }
        }

        return binarySearch(nums, target, 0, pivot) || binarySearch(nums, target, pivot+1, n-1);
    }

    bool binarySearch(vector<int>& nums, int target, int start, int end) {
        int left = start;
        int right = end;
        int middle;

        if (nums.empty()) {
            return false;
        }

        while (left <= right) {
            middle = (right - left) / 2 + left;

            if (nums[middle] == target) {
                return true;
            }

            if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return false;
    }
};

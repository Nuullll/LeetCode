class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // sort orignial vector
        sort(nums.begin(), nums.end());

        // binary search the distance value
        int low = 0, high = 1000000, middle;
        int n = nums.size();

        while (low < high) {
            int count = 0;
            middle = low + (high - low) / 2;    // handle overflow
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= middle) {
                    j++;
                }
                count += j - i - 1;
            }

            if (count < k) {
                low = middle + 1;
            } else {
                high = middle;
            }
        }

        return low;
    }
};

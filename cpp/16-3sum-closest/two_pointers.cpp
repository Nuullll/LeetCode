class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the nums first
        sort(nums.begin(), nums.end());

        int siz = nums.size();
        int i, j, k;
        int remain, sum2, diff;

        if (siz < 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }

        // initialize the closest difference
        int closest = accumulate(nums.begin(), nums.begin() + 3, -target);

        for (int i = 0; i < siz - 2; i++) {
            // left pointer for nums[j]
            // right pointer for nums[k]
            // where i < j < k
            j = i + 1;
            k = siz - 1;

            remain = target - nums[i];

            while (j < k) {
                sum2 = nums[j] + nums[k];
                diff = sum2 - remain;

                if (abs(diff) < abs(closest)) {
                    closest = diff;
                }

                if (diff > 0) {
                    k--;
                } else if (diff < 0) {
                    j++;
                } else {
                    return target;
                }
            }
        }

        return closest + target;
    }
};

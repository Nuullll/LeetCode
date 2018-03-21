class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort the list
        sort(nums.begin(), nums.end());

        vector<vector<int>> results, tmp;
        int i = 0, t;
        int siz = nums.size();

        if (siz < 4) {
            return results;
        }

        while (i < siz - 3) {
            tmp = threeSum(nums, i+1, target-nums[i], siz);
            if (!tmp.empty()) {
                for (auto it = tmp.begin(); it != tmp.end(); it++) {
                    it->push_back(nums[i]);
                    results.push_back(*it);
                }
            }

            t = nums[i];
            while (t == nums[i]) {
                i++;
            }
        }

        return results;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int offset, int target, int siz) {
        int i = offset, j, k;
        int remain, sum2, t;

        vector<vector<int>> results;

        while (i < siz - 2) {
            j = i + 1;
            k = siz - 1;

            remain = target - nums[i];

            while (j < k) {
                sum2 = nums[j] + nums[k];

                if (sum2 == remain) {
                    vector<int> set = {nums[i], nums[j], nums[k]};
                    results.push_back(set);
                    // move j to a different-valued item
                    t = nums[j];
                    while (t == nums[j]) {
                        j++;
                    }

                    continue;
                }

                if (sum2 > remain) {
                    k--;
                } else {
                    j++;
                }
            }

            t = nums[i];
            while (t == nums[i]) {
                i++;
            }
        }

        return results;
    }
};

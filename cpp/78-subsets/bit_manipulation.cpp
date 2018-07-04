class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // O(n*2^n)

        vector<vector<int>> sets;

        int n = nums.size();
        int k = 1 << n;

        int i, j, t;

        for (i = 0; i < k; ++i) {

            vector<int> set;

            j = 0;
            t = i;

            while (t) {
                if (t & 1) {
                    set.push_back(nums[j]);
                }

                ++j;
                t >>= 1;
            }

            sets.push_back(set);
        }

        return sets;
    }
};

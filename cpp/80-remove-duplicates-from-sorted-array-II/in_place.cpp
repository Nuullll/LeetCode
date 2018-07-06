class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Note: input is a sorted array

        int n = nums.size();

        if (n <= 1) {
            return n;
        }

        int value = nums[0];
        int count = 1;
        int marker = 1;
        int len = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] == value) {
                ++count;

                if (count > 2) {
                    // do not move marker
                    continue;
                }
            } else {
                value = nums[i];
                count = 1;
            }

            nums[marker] = value;
            ++marker;
            ++len;
        }

        return len;
    }
};

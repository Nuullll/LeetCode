class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int siz = nums.size();
        int x;

        for (int i = 0; i < siz; i++) {
            x = nums[i];
            while (x > 0 && x <= siz && nums[x-1] != x) {
                swap(nums[i], nums[x-1]);
                x = nums[i];
            }
        }

        for (int i = 0; i < siz; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return siz + 1;
    }
};

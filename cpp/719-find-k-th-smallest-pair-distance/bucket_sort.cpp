class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // loop through all pairs first
        int maxDistance = 1000000;

        vector<int> count(maxDistance, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                count[abs(nums[i] - nums[j])] ++;
            }
        }

        int rank = 0;
        for (int i = 0; i < maxDistance; i++) {
            rank += count[i];
            if (rank >= k) {
                return i;
            }
        }
    }
};

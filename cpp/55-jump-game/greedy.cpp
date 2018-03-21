class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;   // current position
        int next = pos;       // next position
        int jumpRange = nums[pos];  // jump range at current position
        int jumpRange2 = jumpRange;     // jump range of two jumps
        int tmp;

        while (pos + jumpRange < nums.size() - 1) {
            for (int i = 1; i <= jumpRange; i++) {
                tmp = pos + i + nums[pos+i];
                if (tmp >= jumpRange2) {
                    jumpRange2 = tmp;
                    next = pos + i;
                }
            }

            if (pos == next) {
                // cannot move
                return false;
            }

            // jump
            pos = next;
            jumpRange = nums[pos];
            jumpRange2 = jumpRange;
        }

        return true;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea;
        int left = 0, right = height.size() - 1;
        int shorter;

        while (left < right) {
            if (height[left] <= height[right]) {
                shorter = height[left];
                left++;
            } else {
                shorter = height[right];
                right--;
            }

            maxArea = max(maxArea, shorter * (right - left + 1));
        }

        return maxArea;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxLength = 0;
        int n = A.size(), m = B.size();

        vector< vector<int> > dp(n+1, vector<int>(m+1));

        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < m+1; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> pathMaps(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 || j == n - 1) {
                    pathMaps[i][j] = 1;
                } else {
                    pathMaps[i][j] = pathMaps[i+1][j] + pathMaps[i][j+1];
                }
            }
        }

        return pathMaps[0][0];
    }
};

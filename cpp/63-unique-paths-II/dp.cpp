class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> pathMaps(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    pathMaps[i][j] = 0;
                } else if (i == m - 1 && j == n - 1) {
                    pathMaps[i][j] = 1;
                } else if (i == m - 1) {
                    pathMaps[i][j] = pathMaps[i][j+1];
                } else if (j == n - 1) {
                    pathMaps[i][j] = pathMaps[i+1][j];
                } else {
                    pathMaps[i][j] = pathMaps[i+1][j] + pathMaps[i][j+1];
                }
            }
        }

        return pathMaps[0][0];
    }
};

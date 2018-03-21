class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int weight;

        vector<vector<int>> pathMaps(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                weight = grid[i][j];

                if (i == m - 1 && j == n - 1) {
                    pathMaps[i][j] = weight;
                } else if (i == m - 1) {
                    pathMaps[i][j] = weight + pathMaps[i][j+1];
                } else if (j == n - 1) {
                    pathMaps[i][j] = weight + pathMaps[i+1][j];
                } else {
                    pathMaps[i][j] = weight + min(pathMaps[i+1][j], pathMaps[i][j+1]);
                }
            }
        }

        return pathMaps[0][0];
    }
};

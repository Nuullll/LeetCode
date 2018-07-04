class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Use elements in the first column and the first row as the flags

        // Rule: for A[i][j] == 0

        // if i == 0, j > 0
        // then the whole first row needs to be set to zero later
        // use flag: setFirstRow

        // if j == 0, i > 0
        // then the whole first column needs to be set to zero later
        // use flag: setFirstColumn

        // if i > 0 and j > 0
        // then set A[i][0] = A[0][j] = 0
        // which indicates that the corresponding row/column should be set to zero later

        int m = matrix.size();
        int n = matrix[0].size();

        int setFirstRow = 0;
        int setFirstColumn = 0;

        int i, j;

        // loop through the first row
        for (j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                setFirstRow = 1;
                break;
            }
        }

        // loop through the first column
        for (i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                setFirstColumn = 1;
                break;
            }
        }

        // loop through inner area
        for (i = 1; i < m; ++i) {
            for (j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // final: set to zeroes
        // set inner area first
        // loop through the first row
        for (j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // loop through the first column
        for (i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // set boundary zeroes
        if (setFirstRow) {
            for (j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        if (setFirstColumn) {
            for (i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

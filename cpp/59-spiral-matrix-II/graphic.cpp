class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int direction = 0;      // 0:right, 1:down, 2:left, 3:up

        int step = n - 1;       // average length on each direction of each layer
        int i = 0, j = 0;       // start from [0][0] position
        int val = 1;            // from 1 to n^2
        int k;

        while (step >= 0) {
            if (direction == 0) {
                // right, length=step+1
                for (k = 0; k < step+1; k++, val++) {
                    matrix[i][j+k] = val;
                }
                j += step;
                direction = 1;      // go down
            } else if (direction == 1) {
                // down, length=step
                for (k = 1; k < step+1; k++, val++) {
                    matrix[i+k][j] = val;
                }
                i += step;
                direction = 2;      // go left
            } else if (direction == 2) {
                // left, length=step
                for (k = 1; k < step+1; k++, val++) {
                    matrix[i][j-k] = val;
                }
                j -= step;
                direction = 3;      // go up
            } else {
                // up, length=step-1
                for (k = 1; k < step; k++, val++) {
                    matrix[i-k][j] = val;
                }
                i -= step - 1;
                j += 1;
                direction = 0;
                step -= 2;
            }
        }

        return matrix;
    }
};

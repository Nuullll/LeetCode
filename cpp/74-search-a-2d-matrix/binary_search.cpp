class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(logm + logn)

        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> firstCol(m, 0);

        int i;
        pair<int, int> colSearch, rowSearch;

        // fill firstCol vector
        for (i = 0; i < m; ++i) {
            firstCol[i] = matrix[i][0];
        }

        colSearch = binarySearch(firstCol, target);
        int row = colSearch.first;
        int offset = colSearch.second;

        if (row == 0 && offset == -1) {
            return false;
        }

        if (offset == -1) {
            rowSearch = binarySearch(matrix[row - 1], target);
        } else if (offset == 1) {
            rowSearch = binarySearch(matrix[row], target);
        } else {
            return true;
        }

        return rowSearch.second == 0 ? true : false;
    }

    pair<int, int> binarySearch(vector<int> list, int target) {
        // binary search target in the list
        // @return pair<int,int> (index, offset)
        // which indicates the estimated interval in which target should be located
        // if target is hit
        // then offset == 0, target hit @ index
        // else if offset == -1
        // then target locates in (index - 1, index)
        // else (offset == 1)
        // then target locates in (index, index + 1)

        int left = 0;
        int right = list.size() - 1;
        int middle;
        int offset;

        while (left <= right) {

            middle = (right - left) / 2 + left;

            if (target == list[middle]) {
                offset = 0;
                break;
            }

            if (target < list[middle]) {
                right = middle - 1;
                offset = -1;
            } else {
                left = middle + 1;
                offset = 1;
            }
        }

        return pair<int, int> (middle, offset);
    }
};

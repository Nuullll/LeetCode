class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // O(m*n*k)

        if (board.empty() || board[0].empty()) {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visitedMap(m, vector<bool> (n, false));
        vector<tuple<int, int, int>> candidates, matchList;
        vector<tuple<int, int>> routine;
        // tuple(i,j,k) where k is the last matched index of `word`
        // candidates is a stack storing the next possible moves
        // routine is a list storing the current visiting track

        int i, j, k;
        int i_, j_;

        // initialize candidate list
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    // first letter matched
                    candidates.push_back(make_tuple(i, j, 0));
                }
            }
        }

        while (!candidates.empty()) {
            // get next possible move
            tie (i, j, k) = candidates.back();
            candidates.pop_back();

            // do backtracking
            // reverse visited points
            for (vector<tuple<int, int>>::reverse_iterator rit = routine.rbegin(); rit < routine.rend() - k; ++rit) {
                tie (i_, j_) = *rit;
                visitedMap[i_][j_] = false;
            }
            // roll back routine
            routine.erase(routine.begin() + k, routine.end());

            // do visit (i, j)
            routine.push_back(make_tuple(i, j));
            visitedMap[i][j] = true;

            // end of word?
            if (k == word.size() - 1) {
                return true;
            }

            // find next candidates
            matchList = findNextMatches(board, visitedMap, i, j, word, k+1);
            candidates.insert(candidates.end(), matchList.begin(), matchList.end());
        }

        return false;
    }

    vector<tuple<int, int, int>> findNextMatches(const vector<vector<char>>& board, const vector<vector<bool>>& visitedMap, int i, int j, string word, int k) {
        int m = board.size();
        int n = board[0].size();

        vector<tuple<int, int, int>> matchList;

        int i_, j_;

        for (int d = -1; d <= 1; d += 2) {
            i_ = i + d;
            j_ = j;

            if (isValidPoint(i_, j_, m, n) && !visitedMap[i_][j_] && board[i_][j_] == word[k]) {
                matchList.push_back(make_tuple(i_, j_, k));
            }

            i_ = i;
            j_ = j + d;

            if (isValidPoint(i_, j_, m, n) && !visitedMap[i_][j_] && board[i_][j_] == word[k]) {
                matchList.push_back(make_tuple(i_, j_, k));
            }
        }

        return matchList;
    }

    bool isValidPoint(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // O(m*n*k)

        if (board.empty() || board[0].empty()) {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited;
        vector<tuple<int, int, int>> routine, matchList;
        // recording the visited (i, j, k)
        // where k is the last matched index of `word`

        int i, j, k;

        // find all suitable startings
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    // first letter matched
                    routine.push_back(make_tuple(i, j, k));
                }
            }
        }

        if (routine.empty()) {
            return false;
        }

        visited = initVisitedMap(m, n);
        tie (i_, j_, k_) = routine.pop_back();
        visited[i_][j_] = true;
        ++k_;

        while (!routine.empty()) {

            matchList = findNextMatches(board, visited, i, j, word, k);

            routine.insert(routine.end(), matchList.begin(), matchList.end());
        }

    }

    vector<vector<bool>> initVisitedMap(int m, int n) {
        return vector<vector<bool>> (m, vector<bool> (n, false));
    }

    vector<tuple<int, int, int>> findNextMatches(vector<vector<char>> board, vector<vector<bool>> visited, int i, int j, string word, int k) {
        int m = board.size();
        int n = board[0].size();

        vector<tuple<int, int, int>> matchList;

        for (int x = -1; x <= 1; x += 2) {
            for (int y = -1; y <= 1; y += 2) {
                try {
                    if (!visited[i+x][j+y] && board[i+x][j+y] == word[k]) {
                        matchList.push_back(i+x, j+y, k);
                    }
                } catch (const std::out_of_range& e) {
                    // pass
                }
            }
        }

        return matchList;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (this->wordSearch(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool wordSearch(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) {
            return true;
        }

        if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            wordSearch(board, word, i - 1, j, idx + 1) or
            wordSearch(board, word, i + 1, j, idx + 1) or
            wordSearch(board, word, i, j - 1, idx + 1) or
            wordSearch(board, word, i, j + 1, idx + 1);

        board[i][j] = temp;
        return found;
    }
};

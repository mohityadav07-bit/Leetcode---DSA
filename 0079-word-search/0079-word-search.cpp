class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if(k == word.size()) return true;

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k])
            return false;

        char ch = board[i][j];
        board[i][j] = '#';

        bool ans = dfs(board, word, i+1, j, k+1) ||
                   dfs(board, word, i-1, j, k+1) ||
                   dfs(board, word, i, j+1, k+1) ||
                   dfs(board, word, i, j-1, k+1);

        board[i][j] = ch;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        if(word.size() > m*n) return false;

        int freq[128] = {};

        for(auto& row : board)
            for(char c : row)
                freq[c]++;

        for(char c : word)
            if(--freq[c] < 0) return false;

        if(freq[(int)word.back()] > freq[(int)word[0]])
            reverse(word.begin(), word.end());

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
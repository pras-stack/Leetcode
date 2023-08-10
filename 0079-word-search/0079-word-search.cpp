class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Define a DFS (Depth-First Search) function
        function<bool(int, int, int)> dfs = [&](int row, int col, int index) {
            // Base case: If we have matched all characters in the word, return true
            if (index == word.size()) {
                return true;
            }
            
            // Check if current cell is out of bounds or doesn't match the current character
            if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[index]) {
                return false;
            }
            
            // Store the original character and mark the cell as visited
            char original_char = board[row][col];
            board[row][col] = '#';  // Mark cell as visited
            
            // Explore adjacent cells in a depth-first manner
            if (dfs(row - 1, col, index + 1) ||
                dfs(row + 1, col, index + 1) ||
                dfs(row, col - 1, index + 1) ||
                dfs(row, col + 1, index + 1)) {
                return true;  // Word found in adjacent cell
            }
            
            // If not found, backtrack by restoring the original character
            board[row][col] = original_char;  // Backtrack
            return false;
        };
        
        // Iterate through each cell in the board
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Start DFS from each cell and return true if word is found
                if (dfs(row, col, 0)) {
                    return true;
                }
            }
        }
        
        return false;  // Word not found in the entire board
    }
};

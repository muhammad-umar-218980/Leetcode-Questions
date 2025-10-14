class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, collectGold(grid, i, j));
                }
            }
        }
        return maxGold;
    }

private:
    int collectGold(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0) {
            return 0;
        }

        int current = grid[i][j];
        grid[i][j] = 0;

        int up = collectGold(grid, i - 1, j);
        int down = collectGold(grid, i + 1, j);
        int left = collectGold(grid, i, j - 1);
        int right = collectGold(grid, i, j + 1);

        grid[i][j] = current;

        int maxNeighbor = up;
        if (down > maxNeighbor) {
            maxNeighbor = down;
        }
        if (left > maxNeighbor) {
            maxNeighbor = left;
        }
        if (right > maxNeighbor) {
            maxNeighbor = right;
        }

        return current + maxNeighbor;
    }
};

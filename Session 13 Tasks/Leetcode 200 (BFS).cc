class Solution {
public:

    void bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m) {

        queue<pair<int,int>> Q;
        Q.push({i, j});
        vis[i][j] = true;

        int rowDir[4] = {0, 0, 1, -1};
        int colDir[4] = {1, -1, 0, 0};

        while(Q.size() > 0) {

            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();

            for(int k = 0; k < 4; k++) {

                int newRow = row + rowDir[k];
                int newCol = col + colDir[k];

                if(newRow >= 0 and newCol >= 0 and newRow < n and newCol < m) {
                    if(not vis[newRow][newCol] and grid[newRow][newCol] == '1') {
                        vis[newRow][newCol] = true;
                        Q.push({newRow, newCol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1' and not vis[i][j]) {
                    bfs(i, j, vis, grid, n, m);
                    count++;
                }
            }
        }

        return count;
    }
};
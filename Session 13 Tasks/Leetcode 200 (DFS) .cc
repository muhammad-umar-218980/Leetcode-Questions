class Solution {
public:

    void dfs(int i , int j , vector<vector<bool>>& vis , vector<vector<char>>& grid , int n , int m){
        if(i < 0 or j < 0 or i>=n or j >=m or vis[i][j] == true or grid[i][j] != '1') return;

        vis[i][j] = true;

        dfs(i,j+1,vis,grid,n,m);
        dfs(i,j-1,vis,grid,n,m);
        dfs(i+1,j,vis,grid,n,m);
        dfs(i-1,j,vis,grid,n,m);
    }


    int numIslands(vector<vector<char>>& grid) {
        int count = 0 ;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' and not vis[i][j]){
                    dfs(i,j,vis,grid,n,m);
                    count++;
                }
            }
        }

        return count;
    }
};
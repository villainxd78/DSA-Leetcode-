class Solution {
public:
     int dfs(int row,int col,int n, int m,vector<vector<int>>& grid, vector<vector<bool>>&vis){
        vis[row][col]=true;
        int maxArea = 1;

        if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col]==1){
            maxArea +=dfs(row-1,col,n,m,grid,vis);
        }
        if(col+1 < m && !vis[row][col+1] && grid[row][col+1]==1){
            maxArea += dfs(row,col+1,n,m,grid,vis);
        }
        if(row+1 < n && !vis[row+1][col] && grid[row+1][col]==1){
            maxArea += dfs(row+1,col,n,m,grid,vis);
        }

        if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1]==1){
            maxArea +=dfs(row,col-1,n,m,grid,vis);
        }
        return maxArea;
     }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans =0;
       for(int i = 0;i< n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==1 && !vis[i][j]){
            ans =  max(dfs(i,j,n,m,grid,vis),ans);
            }
        }
       }
        
       return ans;
    }
};
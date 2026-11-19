class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<int>>&image, vector<vector<bool>>&vis,int newColor, int oldcolor){
        vis[row][col]=true;
        image[row][col]=newColor;

        if(row-1 >=0 && !vis[row-1][col] && image[row-1][col]==oldcolor){
          dfs(row-1, col, n, m, image,vis,newColor, oldcolor );
       
        }

        if(col+1 < m && !vis[row][col+1] && image[row][col+1]==oldcolor){
          dfs(row, col+1, n, m, image,vis,newColor, oldcolor );
       
        }

        if(row+1 < n && !vis[row+1][col] && image[row+1][col]==oldcolor){
          dfs(row+1, col, n, m, image,vis,newColor, oldcolor );
       
        }

        if(col-1 >=0 && !vis[row][col-1] && image[row][col-1]==oldcolor){
          dfs(row, col-1, n, m, image,vis,newColor, oldcolor );
       
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dfs(sr,sc,n,m,image,vis,newColor,image[sr][sc]);
        return image;
    }
};
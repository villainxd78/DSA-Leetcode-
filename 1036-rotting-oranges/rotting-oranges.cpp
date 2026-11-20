class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                
                }
                }

                    while(!q.empty()){
                       int row = q.front().first.first;
                       int col = q.front().first.second;
                       int time = q.front().second;
                       q.pop();
                       ans = max(ans,time);
                       if(row-1 >= 0 && !visited[row-1][col] && grid[row-1][col]==1){
                        q.push({{row-1,col},time+1});
                        visited[row-1][col]=true;
                       }
                        if(col+1 <m && !visited[row][col+1] && grid[row][col+1]==1){
                        q.push({{row,col+1},time+1});
                        visited[row][col+1]=true;
                       }
                        if(row+1 <n && !visited[row+1][col] && grid[row+1][col]==1){
                        q.push({{row+1,col},time+1});
                        visited[row+1][col]=true;
                       }
                        if(col-1 >= 0 && !visited[row][col-1] && grid[row][col-1]==1){
                        q.push({{row,col-1},time+1});
                        visited[row][col-1]=true;
                       }
                    
                
            
            

        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    return -1;
                }
            }
           
        }
         return ans;
    }
};
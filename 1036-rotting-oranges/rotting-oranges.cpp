class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        int ans = 0;

        vector<vector<bool>>visit(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>Q;

        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(grid[i][j]==2){
                    Q.push({{i,j},0});
                    visit[i][j]=true;
                }
            }
        }
         while(!Q.empty()){
             int row = Q.front().first.first;
             int col = Q.front().first.second;
             int time = Q.front().second;
            Q.pop();
            ans = max(ans,time);
            if(row-1 >=0 && !visit[row-1][col] && grid[row-1][col]==1){
                Q.push({{row-1,col},time+1});
                visit[row-1][col]=true;
            }
            if(col+1 < m && !visit[row][col+1] && grid[row][col+1]==1){
                Q.push({{row,col+1},time+1});
                visit[row][col+1]=true;
            }
            if(row+1 < n && !visit[row+1][col] && grid[row+1][col]==1){
                Q.push({{row+1,col},time+1});
                visit[row+1][col]=true;
            }
            if(col-1 >=0 && !visit[row][col-1] && grid[row][col-1]==1){
                Q.push({{row,col-1},time+1});
                visit[row][col-1]=true;
            }

         }
         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1 && !visit[i][j]){
                    return -1;
                }
            }
         }
         return ans;
    }
};
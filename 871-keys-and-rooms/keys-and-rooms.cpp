class Solution {
public: 
int count = 0;
    void dfs(int src,vector<bool>&vis,vector<vector<int>>&rooms){
        vis[src]=true;
        count ++;
        for(auto & i :rooms[src]){
             if(!vis[i]){

                dfs(i,vis,rooms);
             }

        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);
        count = 0;
        dfs(0,vis,rooms);
        return (count==n);
    }
};
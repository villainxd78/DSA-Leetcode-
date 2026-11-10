class Solution {
public:
    void pathHelper(int src,int dest, vector<bool>vis, vector<int>path,vector<vector<int>>&ans,vector<vector<int>>&graph){
        if(src==dest){
            path.push_back(dest);
            ans.push_back(path);
            path.pop_back();
            return;
        }
           vis[src]=true;
           path.push_back(src);
         for(auto i : graph[src]){
            if(!vis[i]){
                pathHelper(i,dest,vis,path,ans,graph);
            }
         }
         path.pop_back();
         vis[src]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = graph.size()-1;
        vector<bool>vis(graph.size(),false);
        vector<int>path;
        vector<vector<int>>ans;
         pathHelper(src,dest,vis,path,ans,graph);
       return ans;
    }
};
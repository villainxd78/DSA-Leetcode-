class Solution {
public:
    bool helper(int src,int dest,vector<bool>&vis,vector<vector<int>>&l){
         if(src==dest){
            return true;
         }
         vis[src]=true;
         for(int v : l[src]){
            if(!vis[v]){
                if(helper(v,dest,vis,l)){
                    return true;
                }
            }
         }
         return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>l(n);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

           l[u].push_back(v);
           l[v].push_back(u);
        }
        vector<bool>vis(n,false);

        return helper(source,destination,vis,l);
    }
};
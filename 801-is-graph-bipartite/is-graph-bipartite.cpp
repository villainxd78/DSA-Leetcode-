class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int>Q;
        vector<int>color(n , -1);
        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                Q.push(i);
                color[i]=0;

            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();

                for(auto & el : graph[curr]){
                      if(color[el]==-1){
                        color[el] =! color[curr];
                        Q.push(el);
                      }
                      else{
                        if(color[el]==color[curr]){
                            return false;
                        }
                      }
                }
            }
            
            }
        }
        return true;
    }
};
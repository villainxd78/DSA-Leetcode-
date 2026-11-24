class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n , -1);
        queue<int>Q;
        for(int i = 0;i<n;i++){
            if(color[i]== -1){
                color[i]=1;
              Q.push(i);
               
              while(!Q.empty()){
                int curr = Q.front();
                   Q.pop();
                for(auto & el : graph[curr]){
                    if(color[el] == -1 ){
                       color[el] = !color[curr];
                       Q.push(el);
                    }else{
                        if(color[el] == color[curr])
                        return false;
                    }
                }
              }
            }
            
        }
        return true;
    }
};
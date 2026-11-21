class DSU{
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
       for(int i = 0;i<=n;i++){
        parent.push_back(i);
        rank.push_back(1);
       }
    }
    int find(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
    bool unionByRank(int a , int b){
        int pa  = find(a);
        int pb = find(b);

        if(pa == pb){
            return false;
        }
        
        if(rank[a]==rank[b]){
            parent[pb]=pa;
            rank[pa]++;
        }else if( rank[a]>rank[b])
           {
                parent[pb]=pa;
            }else{
                parent[pa]=pb;
            }
        

        return true;
    }
};
class Solution {
public:

    vector<int>findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU graph(n);
        for(int i = 0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(!graph.unionByRank(u,v)){
                return edges[i];
            }
        }
        return {};
    }
};
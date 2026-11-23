class DSU{
    public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        for(int i = 0;i< n;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
    }
    int find (int x){
        if(parent[x]==x){
            return x;
      }
        return parent[x]=find(parent[x]);
    }
    bool unionByRank(int a , int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb){
            return false;
        }
        if (rank[pa]==rank[pb]){
             parent[pb]=pa;
             rank[pa]++;
        }
         else if(rank[pa] > rank[pb]){
            parent[pb] = pa;
         }
         else if(rank[pa] < rank[pb]){
            parent[pa] = pb;
         }
         return true;
    }

     bool isValid(int n, int m,int row, int col){
            return row >=0 && col>=0 && row< n && col < m;
        }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       
         int dr[]= {-1,0,1,0};
         int dc[]={0,1,0,-1};
       
            int  n = grid.size();
           int   m = grid[0].size();   
        DSU graph(n * m);
        
         int count = 0;
         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != '1'){
                    continue;
                }
                count++;

            for(int ind = 0;ind < 4;ind++){
                int adjr = i + dr[ind];
                int adjc = j + dc[ind];

                  if(graph.isValid( n ,  m ,  adjr, adjc) && grid[adjr][adjc]== '1'){
                       int node = i * m + j;
                       int neight = adjr * m + adjc;
                        if(graph.unionByRank(node,neight)){
                            count--;
                        }
                  }
            }
         }
         }
         return count;
    }
};
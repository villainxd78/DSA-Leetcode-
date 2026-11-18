class Solution {
public:
      class info{
        public:
        int u;
        int cost;
        int stops;
        
        info(int u, int cost, int stops){
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }
      };
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<info>Q;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        Q.push(info(src,0,-1));

        while(!Q.empty()){
            info curr = Q.front();
            Q.pop();

            for(int i = 0;i<flights.size();i++){
                if(flights[i][0] == curr.u){
                 int v = flights[i][1];
                 int wt = flights[i][2];

                 if(dist[v] > curr.cost + wt && curr.stops+1 <= k){
                    dist[v] = wt+curr.cost;
                    Q.push(info(v,dist[v],curr.stops+1));
                 }
                }

            }
        }
        if(dist[dst]== INT_MAX){
            return -1;
        }
        return dist[dst];

    }
};
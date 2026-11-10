class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> graph(n + 1);

        for(int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> Q;

        vector<int> color(n + 1, -1);

        for(int i = 1; i <= n; i++) {

            if(color[i] == -1) {

                Q.push(i);
                color[i] = 0;

                while(!Q.empty()) {

                    int curr = Q.front();
                    Q.pop();

                    for(int v : graph[curr]) {

                        if(color[v] == -1) {

                            color[v] = !color[curr];
                            Q.push(v);
                        }
                        else {
                            if(color[v] == color[curr]) {
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
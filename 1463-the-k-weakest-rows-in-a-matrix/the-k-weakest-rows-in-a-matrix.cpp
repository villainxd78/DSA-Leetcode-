class Solution {
public:
    void weakestsoldier(vector<vector<int>>mat,int k,vector<int>&ans){
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i = 0;i<mat.size();i++){
            int count = 0;
            for(int j = 0;j<mat[i].size() && mat[i][j]==1;j++){
                count++;
            }
            pq.push({count,i});
        }
       
        for(int i = 0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();

        }
        
       

    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
     weakestsoldier(mat,k,ans);
     return ans;
     
        
    }
};
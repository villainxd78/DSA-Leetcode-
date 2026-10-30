class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
           mp[nums[i]]++;
        }
        vector<pair<int,int>>p;
        for(auto &it : mp){
            p.push_back({it.second,it.first});
        }
        sort(p.begin(), p.end(), greater<pair<int,int>>());

       vector<int>ans;
       for( int i = 0;i<k;i++){
        ans.push_back(p[i].second);
       }
       return ans;
    }
};
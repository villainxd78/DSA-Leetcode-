class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>bucket(n+2);
        for(auto& it : mp){
            int element = it.first;
            int freq = it.second;
            bucket[freq].push_back(element);
        }
        vector<int>result;
        for(int i = n;i>= 0;i--){
            if(bucket[i].size()==0)
            continue;

            while(bucket[i].size()>0 && k>0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

    return result;
    }
};
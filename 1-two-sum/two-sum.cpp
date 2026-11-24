class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i = 0;i<nums.size();i++){
            int curr = target - nums[i];
            if(m.count(curr)){
                ans.push_back(m[curr]);
                ans.push_back(i);
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};
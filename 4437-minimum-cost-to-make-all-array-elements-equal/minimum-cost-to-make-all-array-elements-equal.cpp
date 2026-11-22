class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        int i = 0;
        while(i<n){
            int j = i;
            while(j< n && nums[i]==nums[j]){
                j++;
            }
            if(j>=2 && i<=n-2){
                long long cost = (long long)nums[i] * i + (long long)nums[i] * (n-j);
                ans = min(ans,cost); 
            }
                 i = j;
        }
        return ans;
    }
};
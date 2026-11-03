class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i = 0;i<nums.size();i+=2){
             int a = nums[i];
             int b = nums[i+1];

             int temp = b;
                while(temp>0){
                    a = a*10;
                    temp = temp/10;
                }
                int merged = a+ b;
                ans = min(ans,merged);
        }
        return ans;
    }
};
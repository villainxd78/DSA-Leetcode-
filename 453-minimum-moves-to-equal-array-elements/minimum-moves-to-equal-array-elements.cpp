class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MAX;
        int sum = 0;
        for(int i = 0;i<n;i++){
            max = min(max,nums[i]);
        }
        for(int i = 0;i<n;i++){
           sum += nums[i]-max;
        }
        return sum;
    }
};
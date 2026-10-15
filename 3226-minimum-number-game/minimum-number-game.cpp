class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        while(i<n){
          swap(nums[i],nums[i+1]);
          i=i+2;
        }
            return nums;

    }
};
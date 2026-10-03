class Solution {
public:
     bool solve(vector<int>&nums,int start,int end,int target){
       if(start>end){
        return false;
       }
       if(start==end){
        return nums[start]==target;
       }
     int mid = start+(end-start)/2;

     if(nums[mid]==target){
        return true;
     }
     if(nums[start]==nums[mid]&&nums[mid]==nums[end]){
        start++;
        end--;

        return solve (nums,start,end,target);
     }

     if(nums[start]<=nums[mid]){
        if(nums[start] <= target && target<nums[mid]){
        return solve(nums,start,mid-1,target);
     }else{
        return solve(nums,mid+1,end,target);
     }
     }else{
        if(nums[mid]<target && target <=nums[end]){
            return solve(nums,mid+1,end,target);
        }
        else{
            return solve(nums,start,mid,target);
        }
     } 
     }
     
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums,0,n-1,target);
        
    }
};
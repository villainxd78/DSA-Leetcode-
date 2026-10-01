class Solution {
public:
int solve(vector<int>& nums, int target, int start, int end) {
           if(start>end){
            return -1;
        }
        int mid = start+(end-start)/2;
       
        if(nums[mid]==target){
            return mid;
        }
        if(nums[start]<=nums[mid]){
        if(nums[start]<=target&& nums[mid]>=target){
            return solve(nums,target,start,mid-1);
        }else{
            return solve(nums,target,mid+1,end);
        }
              
        }else{
            if(nums[mid]<=target && nums[end]>=target ){
                return solve(nums,target,mid+1,end);
            }
            else{
                return solve(nums,target,start,mid-1);
            }
        }
}
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums,target,0,n-1);

        }
    
};
class Solution {
public:

    int solve(vector<int>& nums, int start, int end) {

        if(start == end) {
            return nums[start];
        }

        int mid = start + (end - start) / 2;

        // Left half is sorted
        if(nums[start] <= nums[mid]) {

            // Minimum is on the right
            if(nums[mid] > nums[end]) {
                return solve(nums, mid + 1, end);
            }
            
            // Minimum is on the left
            else {
                return solve(nums, start, mid);
            }
        }

        // Right half is sorted
        else {

            // Minimum is in the left half
            return solve(nums, start, mid);
        }
    }

    int findMin(vector<int>& nums) {

        int n = nums.size();

        return solve(nums, 0, n - 1);
    }
};
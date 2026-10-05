class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lowmax = height[0];
        int highmax = height[n-1];
        int low = 1;
        int high = n-2;
        int ans = 0;

        while(low<=high){
            lowmax = max(lowmax,height[low]);
            highmax = max(highmax,height[high]);
            if(lowmax<highmax){
                ans+= lowmax-height[low];
                low++;
            }else{
                ans+=highmax - height[high];
                high--;
            }
        }
        return ans;
    }
};
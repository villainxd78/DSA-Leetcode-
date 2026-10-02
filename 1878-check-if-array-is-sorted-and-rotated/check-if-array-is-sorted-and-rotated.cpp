class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted(n);
         
         for(int i = 0;i<n;i++){
            int idx = 0;
            for(int j = i;j<n;j++){
                sorted[idx]=nums[j];
                idx++;
            }
             for(int k = 0;k<i;k++){
                sorted[idx]=nums[k];
                idx++;
            }
                    
         
        
         bool issorted = true;
         for(int i = 0;i<n-1;i++){
            if(sorted[i]>sorted[i+1]) {
            issorted = false;
            break;
            
            }
         }
         if(issorted==true){
            return true;
        
         }
         }
         return false;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int cand = -1;
        for(int i = 0;i<n;i++){
            if(count == 0){
                cand = nums[i];
                count++;
            }else if(cand == nums[i])count++;
                   else count--;
            }
            count = 0;
            for(int j = 0;j<n;j++){
                if(nums[j]==cand){
                    count++;
                }
               
                
            }
              if(count>n/2)
               return cand;
                
           
            
        
    
        
        
        return -1;
    }
};
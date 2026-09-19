class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
     int n = nums.size();
     int minelin = min_element(nums.begin(),nums.end())-nums.begin();
     int maxelin = max_element(nums.begin(),nums.end())-nums.begin();

     int left = min(minelin,maxelin);
     int right = max(minelin,maxelin);

     return min({ left+1+n-right,right+1,n-left });
      
    }
    

};
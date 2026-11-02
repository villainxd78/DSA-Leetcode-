class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<pair<int,int>> arr;

        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

       sort(arr.begin(),arr.end());
        int low = 0;
        int high = arr.size()-1;
         
        
        while(low<high){
            if(arr[low].first+arr[high].first==target){
                return {arr[low].second,arr[high].second};
            }else if(arr[low].first + arr[high].first<target){
               low++;
            }else if(arr[low].first+arr[high].first>target){
                 high--;
            }
                
            
        }
        return { };
       

    }
};
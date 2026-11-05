class Solution {
public:
     void intersection(vector<int>& nums1, vector<int>& nums2,vector<int>&ans){
        unordered_set<int>st;
        for(auto &el : nums1){
            st.insert(el);
        }
        for(auto &el :nums2){
            if(st.find(el)!= st.end()){
              ans.push_back(el);
              st.erase(el);
            }

        }
     }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        intersection(nums1,nums2,ans);
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>st;
        vector<vector<string>>ans;
        for(auto & it : strs){
            string temp = it;
            sort(it.begin(),it.end());
            st[it].push_back(temp);
        }
        for(auto & it : st){
            ans.push_back(it.second);
        }
        return ans;
    }
};
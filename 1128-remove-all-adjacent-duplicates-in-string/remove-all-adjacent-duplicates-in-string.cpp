class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0;i<n;i++){
            char curr = s[i];
            if(!st.empty() && curr == st.top()){
                st.pop();
            }else{
            st.push(curr);
            }
            
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
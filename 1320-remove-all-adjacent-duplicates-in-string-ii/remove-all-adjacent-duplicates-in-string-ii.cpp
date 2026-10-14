class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(!st.empty() && ch == st.top().first){
                  st.top().second++;
                  if(st.top().second==k){
                    st.pop();
                  }
            }else{
                st.push({ch,1});
            }
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top().first;
            int freq = st.top().second;

            for(int i = 0;i<freq;i++){
               ans.push_back(ch);
            }
                        st.pop();  

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
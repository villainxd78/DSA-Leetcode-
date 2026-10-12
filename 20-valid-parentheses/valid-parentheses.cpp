class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;
        for(int i = 0;i<n;i++){
           char ch = s[i];

           if(s[i]=='(' || s[i]=='{'||s[i]=='['){
            st.push(ch);
           }else{
               if(st.empty()){
               return false;

               }
                if(ch==')'&& st.top()!='('){
            return false;
           }
           if(ch=='}' && st.top()!='{'){
            return false;
           }
           if(ch==']'&& st.top()!='['){
            return false;
           }
           st.pop();
           }
          
        }
        return st.empty();
    }
};
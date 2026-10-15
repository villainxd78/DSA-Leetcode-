class Solution {
public:
    string decodeString(string s) {
        stack<int>st;
        stack<string>st1;
        int n= 0;
        string sb = "";
        for(char ch:s){
            if(isdigit(ch)){
              n= n * 10 +(ch - '0');
              
            }else if(ch == '['){
                st.push(n);
                n= 0;
                st1.push(sb);
                sb = "";
            }else if(ch == ']'){
                 int k = st.top();
                 st.pop();
                 string temp = sb;
                 sb = st1.top();
                 st1.pop();
                 while(k>0){
                    sb = sb + temp;

                    k--;
                   
                 }
            }else{
                sb += ch;
            }
        }
        return sb;
    }
};
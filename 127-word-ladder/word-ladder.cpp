class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>Q;
        Q.push({beginWord,1});

        while(!Q.empty()){
            string str = Q.front().first;
            int len = Q.front().second;
             Q.pop();
             if(str == endWord){
                return len;
             }
             for(int i = 0;i<str.length();i++){
                char original = str[i];
               for(char ch = 'a'; ch<= 'z'; ch++){
                str[i]=ch;
                if(st.find(str)!= st.end()){
                    Q.push({str,len+1});
                    st.erase(str);
                }
               }
               str[i]=original;
             }
            }
           return 0;
           }
        };
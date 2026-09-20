class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        vector<bool>isvalid(26,false);
        vector<string>result;

        for(int i = 0;i<n;i++){
            int index = s[i]-'a';

            if(start[index]==-1){
                start[index]=i;
            }
            end[index]=i;
            
        }
        for(int c = 0;c<26;c++){
            if(start[c]==-1)continue;
             isvalid[c] = true;

            for(int i = start[c];i<=end[c];i++){
                if(start[s[i]-'a']<start[c]){
                    isvalid[c]= false;
                    break;
                }
                end[c]=max(end[c],end[s[i]-'a']);
            }
            
                }
                int lasttakenstart = INT_MAX;
            for(int i = n-1;i>=0;i--){
                int idx = s[i]-'a';

                if(!isvalid[idx]) continue;

                if(i==start[idx]&&end[idx]<lasttakenstart){
                    result.push_back(s.substr(i,end[idx]-i+1));
                    lasttakenstart = i;

            }
           
        }
 return result;

    }
};
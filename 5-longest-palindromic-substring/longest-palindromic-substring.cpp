class Solution {
public:
    int solve(string& s , int st , int ed  , vector<vector<int>>& dp ){
        if(st > ed ) return 0 ; 
        if(dp[st][ed] != -1 ) return dp[st][ed];
        if(st == ed ) return dp[st][ed] =  1 ; 
        solve(s , st + 1 , ed , dp ) ; 
        solve(s , st , ed - 1  , dp );
        if(s[st] == s[ed]) return dp[st][ed] = 2 +  solve(s , st + 1 , ed - 1 , dp );
         return dp[st][ed] = INT_MIN ; 
    }
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size() , vector<int>(s.size() , -1 ))  ; 
        solve(s , 0 , s.size() - 1 ,  dp);
        int st  , ed ; 
        int maxx = INT_MIN ; 
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = 0 ; j < s.size() ; j++) {
                if(maxx < dp[i][j]){
                    maxx = dp[i][j];
                    st = i ; 
                    ed = j ; 
                }
            }
        }
    return s.substr(st , ed - st + 1 );
    }
};
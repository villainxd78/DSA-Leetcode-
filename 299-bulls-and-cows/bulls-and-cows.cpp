class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>secretmap,guessmap;
        int bulls = 0;
        int cow = 0;
        for(int i = 0;i<secret.size();i++){
             if(secret[i]==guess[i]){
                bulls++;
             }else{
                secretmap[secret[i]]++;
                guessmap[guess[i]]++;
             }
        }
        for(auto & el : secretmap){
            char c = el.first;
            int freq_secret = el.second;
            int freq_guess = guessmap[c];
            cow += min(freq_secret,freq_guess);
        }
        return to_string(bulls)+"A" + to_string(cow)+"B";
    }
};
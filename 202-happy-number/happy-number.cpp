class Solution {
public:
     int sumofSquare(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            n /=10;
            sum += (digit * digit);
        }
        return sum;
     }
    bool isHappy(int n) {
        unordered_set<int>st;

        while(n!=1){
           if(st.contains(n)){
            return false;
           }else{
              st.insert(n);
             n= sumofSquare(n);
           }
            
           
        }
        return true;
     

    }
};
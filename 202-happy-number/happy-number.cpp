class Solution {
public:
    int getsum (int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            n/=10;
            sum+= (digit * digit);
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
           slow = getsum(slow);
        fast = getsum(getsum(fast));
       
         while(slow!=fast){
             slow = getsum(slow);
        fast = getsum(getsum(fast));
         }
         if (slow == 1){
           return true;
         }
         
         else{
         return false;
         }
         
        
        
    }

};
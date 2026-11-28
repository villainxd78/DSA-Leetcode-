class Solution {
public:
     int fib(vector<int>&ans, int n){
        if (n==0 ){
            return 0;
        }
         if(n==1 ){
            return 1;
        }
        if(n==2){
            return 1;
        }
        if(ans[n] != -1){
            return ans[n];
        }
        return ans[n]= fib(ans, n-1) + fib(ans, n-2)+fib(ans, n-3);
     }
    int tribonacci(int n) {
        vector<int>ans(n+1,-1);
        return fib(ans,n);
    }
};
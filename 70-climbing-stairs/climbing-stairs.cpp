class Solution {
public: 
     int count(int n , vector<int>&a){
        if(n==0 || n==1){
            return 1;
        }
        if(a[n] != -1){
            return a[n];
        }
        a[n] = count(n-1,a) + count(n-2,a);
        return a[n];
     }

    int climbStairs(int n) {
        vector<int>a(n+1,-1);
        return count(n,a) ;
    }
};
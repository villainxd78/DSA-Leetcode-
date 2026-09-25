class Solution {
public:
   long long pow(long long a,long long b){
   long long m = 1000000007;
    if(b == 0) return 1;
    long long temp = pow(a,b/2);
    if(b%2 ==0){
        return (temp * temp)%m;
    }else{
        return ((temp* temp)%m * a)%m;
    }
    
        
    }
   
    int countGoodNumbers(long long n) {
        long long m = 1000000007;
        return (pow(5,(n+1)/2) * pow(4,n/2))%m;
    }
};
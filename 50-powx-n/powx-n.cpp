class Solution {
public:
   double pow(double x,int n){
    if(n==0){
        return 1;
    }
    double temp = pow(x,n/2);
    if(n%2==0){
          return temp *temp;
    }else{
        return temp * temp * x;
    }
   }
    double myPow(double x, int n) {
        if(n==INT_MIN){
            return pow(1/x,INT_MAX-1);
        }
        if(x==0||x==1){
            return x;
        }
        if(n<0)return pow(1/x,-n);
        return pow(x,n);
    }
};
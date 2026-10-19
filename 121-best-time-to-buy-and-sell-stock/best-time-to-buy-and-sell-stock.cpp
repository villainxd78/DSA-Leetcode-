class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mi = prices[0];
        int profit = 0;
        for(int i = 1;i<n;i++){
            int curr = prices[i] - mi;
            if(curr>profit){
               profit=curr;
            }
            if(prices[i]<mi){
                mi = prices[i];
            }
        }
        return profit;
    }
};
class Solution {
public:
    int stocks(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp, int fee){
        if(idx >= prices.size())
            return 0;
        
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        int profit = 0;
        if(buy){
            int buyKaro = -prices[idx] + stocks(idx + 1, 0, prices, dp, fee);
            int ignoreKaro = stocks(idx + 1, 1, prices, dp, fee);
            profit = max(buyKaro, ignoreKaro);
        }
        else{
            int sellKaro = prices[idx] + stocks(idx + 1, 1, prices, dp, fee) - fee;
            int ignoreKaro = stocks(idx + 1, 0, prices, dp, fee);
            profit = max(sellKaro, ignoreKaro);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return stocks(0, 1, prices, dp, fee);
    }
};
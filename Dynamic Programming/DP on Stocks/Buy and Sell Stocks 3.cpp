class Solution {
public:
    int stocks(int idx, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp, int k){
        if(k == 0)  
            return 0;
        if(idx == prices.size())
            return 0;

        if(dp[idx][buy][k] != -1)
            return dp[idx][buy][k];

        
        int profit = 0;
        if(buy){
            int buyKaro = -prices[idx] + stocks(idx + 1, 0, prices, dp, k);
            int ignoreKaro = stocks(idx + 1, 1, prices, dp, k);
            profit = max(buyKaro, ignoreKaro);
        }
        else{
            int sellKaro = prices[idx] + stocks(idx + 1, 1, prices, dp, k-1);
            int ignoreKaro = stocks(idx + 1, 0, prices, dp, k);
            profit = max(sellKaro, ignoreKaro);
        }
        return dp[idx][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return stocks(0, 1, prices, dp, k);
        // return bottomUp(prices, n, k);
    }
};
class Solution {
public:
    int f(int i,int t,vector<int>& coins,vector<vector<int>>&dp){
        if(i==0){
            if(t%coins[0]==0) return t/coins[0];
            else return 1e9;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int nt=0+f(i-1,t,coins,dp);
        int tt=1e9;
        if(coins[i]<=t){
            tt=1+f(i,t-coins[i],coins,dp);
        }
        return dp[i][t]=min(tt,nt);
    }
    int coinChange(vector<int>& coins, int t) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        int x=f(n-1,t,coins,dp);
        if(x!=1e9) return x;
        else return -1;
    }
};
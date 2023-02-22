class Solution {
public:
    int f(int idx, vector<int> &dp){
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2; i<idx+1; i++)
            dp[i]=dp[i-1]+dp[i-2];
        
        return dp[idx];
    }
    int climbStairs(int n){
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};
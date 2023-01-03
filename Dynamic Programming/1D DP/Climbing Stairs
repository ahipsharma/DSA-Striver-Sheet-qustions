class Solution {
public:
    // Memoized approach, Top Down approach:
    // int countWays(int n, vector<int> dp){
    //     if(n == 0 || n == 1)
    //         return 1;
        
    //     if(dp[n] != -1)
    //         return dp[n];

    //     return dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1, -1);
    //     return countWays(n, dp);
    // }

    // Tabulated/Bottom Up Approach:

    int climbStairs(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};
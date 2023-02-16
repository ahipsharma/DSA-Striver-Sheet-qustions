class Solution{
public:
    int f(int *wt, int *val, int ind, int W, vector<vector<int>>& dp){

        if(ind == 0)
            return ((int)(W/wt[0])) * val[0];
        
        if(dp[ind][W]!=-1)
            return dp[ind][W];
            
        int notTaken = 0 + f(wt,val,ind-1,W,dp);
        
        int taken = INT_MIN;
        if(wt[ind] <= W)
            taken = val[ind] + f(wt,val,ind,W-wt[ind],dp);
            
        return dp[ind][W] = max(notTaken,taken);
    }
    int knapSack(int n, int W, int val[], int wt[]){
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return f(wt, val, n-1, W, dp);
    }
};
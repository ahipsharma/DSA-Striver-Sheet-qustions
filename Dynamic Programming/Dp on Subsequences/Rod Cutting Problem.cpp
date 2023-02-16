class Solution{
  public:
    int cutRodUtil(int *price, int ind, int N, vector<vector<int>>& dp){

        if(ind == 0){
            return N*price[0];
        }
        
        if(dp[ind][N]!=-1)
            return dp[ind][N];
            
        int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
        
        int taken = INT_MIN;
        int rodLength = ind+1;
        if(rodLength <= N)
            taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);
            
        return dp[ind][N] = max(notTaken,taken);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return cutRodUtil(price,n-1,n,dp);
    }
};
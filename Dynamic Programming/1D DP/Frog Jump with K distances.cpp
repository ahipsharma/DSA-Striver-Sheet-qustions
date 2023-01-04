class Solution {
  public:
  int Recursive(vector<int>& height, int n, int k){
        if(n == 0)
            return 0;
        
        int mini = INT_MAX;
        for(int i = 1;i<=k;i++){
            if((n-i)>=0){
                int jump = Recursive(height, n-i, k) + abs(height[n] - height[n-i]);
                mini = min(mini, jump);
            }
        }
        return mini;
    }
    
    
    int Memoized(vector<int>& height, int n, int k, vector<int> dp){
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        int mini = INT_MAX;
        for(int i = 1;i<=k;i++){
            if((n-i)>=0){
                int jump = Memoized(height, n-i, k, dp) + abs(height[n] - height[n-i]);
                mini = min(mini, jump);
            }
        }
        return dp[n] = mini;
    }
    
    
    int BottomUp(vector<int>& height, int n, int k, vector<int> dp){
        dp[0]=0;
        for(int i=1;i<n;i++){
            int mini = INT_MAX;
            
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                    mini= min(jump, mini);
                }
            }
            dp[i]= mini;
        }
        return dp[n-1];
    }
    
    
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, -1);
        
        // Recursive Solution:
        
        // return Recursive(height, n-1, k);
        
        // Memoized Solution:
        
        // return Memoized(height, n-1, k, dp);
        
        // BottomUp approach:
        return BottomUp(height, n, k, dp);
    }
};
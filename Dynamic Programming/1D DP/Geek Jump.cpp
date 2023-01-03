class Solution {
  public:
  
  
    // Recursive Solution:   
    int Recursive(vector<int>& height, int indx){
        if(indx == 0)   return 0;
        int jump1 = Recursive(height, indx - 1) + abs(height[indx] - height[indx - 1]), jump2 = INT_MAX;
        if(indx > 1)
            jump2 = Recursive(height, indx - 2) + abs(height[indx] - height[indx - 2]);
            
        return min(jump1, jump2);
    }
    
    
    
    // Top Down/ Memoized approach:
    // However, this results in TLE so use the Bottom Up approach.
    int TopDown(vector<int>& height, int indx, vector<int> dp){
        if(indx == 0)   return 0;
        
        if(dp[indx] != -1) return dp[indx];
        
        int jump1 = TopDown(height, indx - 1, dp) + abs(height[indx] - height[indx - 1]), jump2 = INT_MAX;
        if(indx > 1)
            jump2 = TopDown(height, indx - 2, dp) + abs(height[indx] - height[indx - 2]);
        
        return dp[indx] = min(jump1, jump2);
    }
    
    int BottomUp(vector<int>& height, int indx){
        int n=height.size();
        vector<int> dp(indx,-1);
        dp[0]=0;
        for(int ind=1;ind<indx;ind++){
            int jumpTwo = INT_MAX;
            int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
            if(ind>1)
                jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
        
            dp[ind]=min(jumpOne, jumpTwo);
        }
        return dp[indx-1];
    }
    int minimumEnergy(vector<int>& height, int indx) {
        // vector<int> dp(indx, -1);
        
        // return Recursive(height, indx-1);
        
        // return TopDown(height, indx-1, dp);
        
        return BottomUp(height, indx);
    }
};
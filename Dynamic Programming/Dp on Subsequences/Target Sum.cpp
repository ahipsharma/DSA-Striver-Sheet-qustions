class Solution {
  public:
    int f(int idx, vector<int>&arr ,int target, vector<vector<int>> &dp){
        if(idx == 0){
            if(target == 0 && arr[0] == 0)
                return 2;
            if(target == 0 || arr[0] == target)
                return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        
        int notake = f(idx - 1, arr, target, dp);
        int take = 0;
        
        
        if(arr[idx] <= target)
            take = f(idx - 1, arr, target - arr[idx], dp);
        
        
        return dp[idx][target] = (take + notake);
    }
    int findTargetSumWays(vector<int>&arr ,int target) {
        int totSum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
            totSum += arr[i];
        
        int sum = totSum - target;
        if(sum < 0) return 0;
        if(sum%2 == 1) return 0;
        int s2 = (totSum - target)/2;
        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        return f(n-1, arr, s2, dp);
    }
};
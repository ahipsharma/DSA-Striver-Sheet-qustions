class Solution{   
public:
    bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target==0)
            return true;
        
        if(ind == 0)
            return arr[0] == target;
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
            
        bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
        
        bool taken = false;
        if(arr[ind]<=target)
            taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
            
        return dp[ind][target]= notTaken||taken;
    }
    
    bool isSubsetSum(vector<int> &arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        return subsetSumUtil(n-1,sum,arr,dp);
    }
};
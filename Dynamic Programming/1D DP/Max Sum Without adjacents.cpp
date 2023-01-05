class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int Recursion(int arr[], int ind){
	    if(ind == 0)
	        return arr[ind];
	    if(ind < 0)
	        return 0;
	    int pick = arr[ind] + Recursion(arr, ind - 2);
	    int notpick = Recursion(arr, ind - 1);
	    return max(pick, notpick);
	}
	
	int Memoization(int arr[], int ind, vector<int> dp){
	    if(ind == 0)
	        return arr[ind];
	    if(ind < 0)
	        return 0;
	    
	    if(dp[ind] != -1) return dp[ind];
	    
	    int pick = arr[ind] + Memoization(arr, ind - 2, dp);
	    int notpick = Memoization(arr, ind - 1, dp);
	    return dp[ind] = max(pick, notpick);
	}
	
	int BottomUp(int arr[], int n, vector<int> dp){
	    dp[0]= arr[0];
    
        for(int i=1 ;i<n; i++){
            int pick = arr[i];
            if(i>1)
                pick += dp[i-2];
            int nonPick = dp[i-1];
            
            dp[i]= max(pick, nonPick);
        }
        
        
        return dp[n-1];
	}
	
	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	    
	    // Recursion approach (results in TLE though).
	    // return Recursion(arr, n-1);
	    
	    // Memoization approach
	   // return Memoization(arr, n-1, dp);
	    
	    // Bottom Up Approach:
	    return BottomUp(arr, n, dp);
	    
	    
	}
};
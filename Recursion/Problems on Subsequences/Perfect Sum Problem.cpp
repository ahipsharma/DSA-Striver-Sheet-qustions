class Solution{
public:
    const int x=1000000007;

    int func(int arr[], int n, int sum, vector<vector<int>> &dp) {

        if(sum==0 && n==-1)
            return 1;
        if(n<0)return 0;
    
        if(dp[sum][n]!=-1) return dp[sum][n];
    
        if(sum<arr[n]) return dp[sum][n]=func(arr,n-1,sum,dp)%x;
    
        else return dp[sum][n]=(func(arr,n-1,sum-arr[n],dp)+func(arr,n-1,sum,dp))%x;
    }
    int perfectSum(int arr[], int n, int sum){

        // Your code goes here

        int cnt=0;

        vector<vector<int>>dp(sum+1,vector<int>(n,-1));

        return (int) func(arr,n-1,sum,dp);

    }
};
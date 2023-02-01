class Solution{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // int Recursion(int i, int j, string s1, string s2){
    //     if(i<0 || j<0)
    //         return 0;
        
    //     if(s1[i] == s2[j])
    //         return 1 + Recursion(i-1, j-1, s1, s2);
        
    //     return max(Recursion(i-1, j, s1, s2), Recursion(i, j-1, s1, s2));
    // }
    
    // int Memoization(int i, int j, string s1, string s2, vector<vector<int>> dp){
    //     if(i<0 || j<0)
    //         return 0;
            
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     if(s1[i] == s2[j])
    //         return dp[i][j] = 1 + Memoization(i-1, j-1, s1, s2, dp);
        
    //     return dp[i][j] = max(Memoization(i-1, j, s1, s2, dp), Memoization(i, j-1, s1, s2, dp));
    // }
    
    int Tabulation(int n1, int n2, string s1, string s2){
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int j=0;j<=n2;j++) dp[0][j]=0; // base case
        for(int i=0;i<=n1;i++) dp[i][0]=0; // base case

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    int res1=dp[i-1][j];
                    int res2=dp[i][j-1];
                    dp[i][j]= max(res1,res2);
                }
            }
        }
        return dp[n1][n2];
    }
    
    int lcs(int x, int y, string s1, string s2){
        // return Recursion(x-1, y-1, s1, s2);
        
        vector<vector<int>> dp(x, vector<int>(y, -1));
        // return Memoization(x-1, y-1, s1, s2, dp);
        return Tabulation(x, y, s1, s2);
        
    }
};
class Solution{
    public:
    int f(int n, int m, string s1, string s2){
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = 0;
        
        for(int i=0; i<n; i++) dp[i][0]=0;
        for(int j=0; j<n; j++) dp[0][j]=0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }
    int longestCommonSubstr (string s1, string s2, int n, int m){
        return f(n, m, s1, s2);
    }
};
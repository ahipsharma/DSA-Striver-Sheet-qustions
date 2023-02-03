class Solution{
    public:
    int Tabulation(int n1, int n2, string s1, string s2){
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        int ans = 0;
        for(int i=0; i<=n1; i++) dp[i][0] = 0;
        for(int j=0; j<=n2; j++) dp[0][j] = 0;
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
    int longestCommonSubstr (string s1, string s2, int n, int m){
        return Tabulation(n, m, s1, s2);
    }
};
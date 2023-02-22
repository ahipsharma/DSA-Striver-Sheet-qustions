class Solution{
  public:
    string rev(string str){
        string s1="";
        for(int i=str.length()-1; i>=0; i++)
            s1+=str[i];
        return s1;
    }
    int f(int n, int m, string s1, string s2){
        int ans = 0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int j=0; j<=n; j++) dp[0][j]=0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
        
    }
    int longestPalinSubseq(string str) {
        string s2 = rev(s1);
        
    }
};
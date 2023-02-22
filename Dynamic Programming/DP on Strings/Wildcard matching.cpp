class Solution{
  public:
    int f(int i, int j, string &pattern, string &str, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        
        if(j < 0 && i >= 0){
            for(int k=0; k<=i; k++){
                if(pattern[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(pattern[i] == str[j] || pattern[i] == '?')
            return dp[i][j] = f(i-1, j-1, pattern, str, dp);
        if(pattern[i] == '*')
            return dp[i][j] = f(i-1, j, pattern, str) || f(i, j-1, pattern, str);
        return false;
    }
    
    int wildCard(string pattern,string str) {
        int n=pattern.length();
        int m=str.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, pattern, str, dp);
    }
};
class Solution
{
    public:
    int paths(int a, int b){
        if(a == 0 && b == 0)
            return 1;
        if(a<0 || b<0)
            return 0;
        
        int left = paths(a, b - 1);
        int up = paths(a - 1, b);
        return left+up;
    }
    int Memoization(int a, int b, vector<vector<int>> dp){
        if(a == 0 && b == 0)
            return 1;
        if(a < 0 || b < 0)
            return 0;
        
        if(dp[a][b] != -1)
            return dp[a][b];
            
        return dp[a][b] = (Memoization(a, b-1, dp) + Memoization(a-1, b, dp));
    }
    
    int Tabulated(int a, int b, vector<vector<int> > dp){
        for(int i=0; i<a ;i++){
            for(int j=0; j<b; j++){
          
                //base condition
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
              
                int up=0;
                int left = 0;
              
                if(i>0) 
                  up = dp[i-1][j];
                if(j>0)
                  left = dp[i][j-1];
                
                dp[i][j] = up+left;
            }
        }
        return dp[a-1][b-1];
    }
    
    int NumberOfPath(int a, int b){
        // return paths(a-1, b-1);
        vector<vector<int> > dp(a,vector<int>(b,-1));
        // return Memoization(a-1, b-1, dp);
        return Tabulated(a, b, dp);
    }
};
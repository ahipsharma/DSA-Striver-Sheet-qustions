class Solution {
public:
    int Triangle(int i, int j, vector<vector<int>>& mat, int n){
        if(i == n-1)
            return mat[i][j];
        
        int down = mat[i][j] + Triangle(i+1, j, mat, n);
        int diag = mat[i][j] + Triangle(i+1, j+1, mat, n);

        return min(down, diag);
    }
    int minimumPathSumUtil(int i, int j, vector<vector<int>> &mat,int n, vector<vector<int>> &dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i == n-1) return mat[i][j];
            
        int down = mat[i][j]+minimumPathSumUtil(i+1, j, mat, n, dp);
        int diagonal = mat[i][j]+minimumPathSumUtil(i+1, j+1, mat, n, dp);
        
        return dp[i][j] = min(down, diagonal);
    }
    int TriangleMemoized(int i, int j, vector<vector<int>>& mat, vector<vector<int>> dp, int n){
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == n-1) return mat[i][j];

        int down = mat[i][j] + TriangleMemoized(i+1, j, mat, dp, n);
        int diag = mat[i][j] + TriangleMemoized(i+1, j+1, mat, dp, n);

        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        // return Triangle(0, 0, mat, n);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return TriangleMemoized(0, 0, mat, dp, n);
        return minimumPathSumUtil(0, 0, mat, n, dp);
    }
};
// For LeetCode:

class Solution{
    public:
    //Function to find length of shortest common supersequence of two strings.
    string Tabulation(int n1, int n2, string s1, string s2){
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int j=0;j<=n2;j++) dp[0][j]=0; // base case
        for(int i=0;i<=n1;i++) dp[i][0]=0; // base case

        for(int i=1 ; i<=n1 ; i++){
            for(int j=1 ; j<=n2 ; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1 ;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
                }
            }
        }
        
        int n = dp[n1][n2];
        string str = "";
        int i = n1, j=n2;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                str += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                str += s1[i-1];
                i--;
            }
            else{
                str +=s2[j-1];
                j--;
            }
        }
        while(i>0){
            str += s1[i-1];
            i--;
        }
        while(j>0){
            str +=s2[j-1];
            j--;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string shortestCommonSupersequence(string s1, string s2){
        int n1 = s1.length(), n2 = s2.length();
        return Tabulation(n1, n2, s1, s2);
    }
};

// For GeeksforGeeks


// class Solution{
//     public:
//     //Function to find length of shortest common supersequence of two strings.
//     int shortestCommonSupersequence(string s1, string s2, int x, int y){
//         int dp[x+1][y+1] ; 
//         for(int i=0 ; i<=x ; i++){
//             dp[i][0]=0 ; 
//         }
//         for(int i=0 ; i<=y ; i++){
//             dp[0][i]=0 ; 
//         }
//         for(int i=1 ; i<=x ; i++){
//             for(int j=1 ; j<=y ; j++){
//                 if(s1[i-1]==s2[j-1]){
//                     dp[i][j] = dp[i-1][j-1]+1 ;
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
//                 }
//             }
//         }
//         return x+y-dp[x][y] ;
//     }
// };
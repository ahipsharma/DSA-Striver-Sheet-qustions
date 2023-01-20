class Solution {
  public:
    int Recursion(vector<vector<int>>& points, int days, int lastevent){
        if(days == 0){
            int maxi = 0;
            for(int task = 0;task<=2; task++)
                if(task != lastevent)
                    maxi = max(maxi, points[days][task]);
            return maxi;
        }
        
        int maxi = 0;
        for(int task = 0; task<=2;task++){
            if(task != lastevent){
                int point = points[days][task] + Recursion(points, days - 1, lastevent);
                maxi = max(maxi, point);
            }
        }
        return maxi;
    }
    int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {
        if (dp[day][last] != -1) return dp[day][last];

        if (day == 0) {
            int maxi = 0;
            for (int i = 0; i <= 2; i++) {
                if (i != last)
                    maxi = max(maxi, points[0][i]);
            }
        return dp[day][last] = maxi;
        }

    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            int activity = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }

  return dp[day][last] = maxi;
}
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        // return Recursion(points, n - 1, 3);
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n-1, 3, points, dp);
        // return Memoization(points, n-1, 3, dp);
    }
};
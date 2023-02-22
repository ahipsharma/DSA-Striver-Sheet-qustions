class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int> &dp){
        if(idx == 0)
            return nums[0];
        if(idx<0)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];

        int notpick = f(idx-1, nums, dp);
        int pick = nums[idx] + f(idx-2, nums, dp);
        
        return dp[idx] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int>v1(nums.begin(), nums.begin()+nums.size()-1), v2(nums.begin()+1, nums.end());
        vector<int> dp1(n-1, -1), dp2(n-1, -1);
        return max(f(n-2, v1, dp1), f(n-2, v2, dp2));
    }
};
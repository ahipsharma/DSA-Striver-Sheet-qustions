class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int len = nums.size();
        int profit = 0;
        int mini = nums[0];

        for(int i=1; i<len; i++){
            int diff = nums[i] - mini;
            profit = max(diff, profit);
            mini = min(mini, nums[i]);
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit = 0, buy = nums[0], n = nums.size();
        for(int i=1; i<n; i++){
            int diff = nums[i] - buy;
            profit = max(diff, profit);
            buy = min(buy, nums[i]);
        }
        return profit;
    }
};
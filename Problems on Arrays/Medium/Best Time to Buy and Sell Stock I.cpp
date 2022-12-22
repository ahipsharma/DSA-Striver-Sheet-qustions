class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int min = INT_MAX, tp = 0, op = 0; // tp = Today's profit, op = Overall Profit.
        for(int i = 0; i<nums.size(); i++){
            if(min>nums[i])
                min = nums[i];
            
            tp = nums[i] - min;
            if(op < tp)
                op = tp;
        }
        return op;

    }
};
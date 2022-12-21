class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), c = 0, maxi = 0;
        for(int i:nums)
            if(i == 1)  maxi = max(maxi, ++c);
            else c = 0;
        return maxi;
    }
};
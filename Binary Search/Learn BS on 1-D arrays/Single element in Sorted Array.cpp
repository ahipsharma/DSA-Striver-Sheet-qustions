class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = 0;
        for(int i:nums)
            x = x^i;
        return x;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, n = nums.size();
        for(int k = 0;k<n;k++){
            if(nums[k] != 0)
                nums[j++] = nums[k];
        }
        for(;j<n;j++){
            nums[j] = 0;
        }
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 1st method:
        // int n = nums.size();
        // k %= nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k, nums.end()); 

        // 2nd method:
        vector<int> temp(nums.size());
        for(int i = 0;i<nums.size();i++)
            temp[(i+k)%nums.size()] = nums[i];
        
        nums = temp;
    }
};
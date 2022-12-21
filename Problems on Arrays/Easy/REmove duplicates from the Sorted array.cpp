class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            set.insert(nums[i]);
        }
        int j = 0;
        for(auto it:set){
            nums[j++] = it;
        }
        return set.size();
    }
};
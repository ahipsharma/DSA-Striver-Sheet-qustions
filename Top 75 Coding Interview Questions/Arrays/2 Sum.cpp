class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int x) {
        vector<int> ans;
        map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(mp.find(x-nums[i]) != mp.end()){
                ans.push_back(mp[x-nums[i]]);
                ans.push_back(i);
            }
            mp.insert({nums[i], i});
        }
        return ans;
    }
};
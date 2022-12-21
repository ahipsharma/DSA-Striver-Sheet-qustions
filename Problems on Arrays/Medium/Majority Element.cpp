class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size(), ans;
        for(int i:nums)
            mp[i]++;
        
        int val;
        int max = INT_MIN;
        for(auto it:mp)
            if(it.second > max){
                val = it.first;
                max = it.second;
            }
        return val;
    }
};
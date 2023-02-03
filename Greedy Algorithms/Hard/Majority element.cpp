class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int,int> m;
        int n = nums.size();
        if(n == 1){
            ans.push_back(nums[0]);
            return ans;
        }
        for(int i = 0;i<n;i++){
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
        }
        for(auto it:m){
            if(it.second > (n/3))
                ans.push_back(it.first);
        }
        return ans;
    }
};
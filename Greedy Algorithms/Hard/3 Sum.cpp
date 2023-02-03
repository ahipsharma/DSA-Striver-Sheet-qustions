class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i == 0 || (i>0 && nums[i] != nums[i-1])){
                int lo = i+1, hi = nums.size()-1, sum = 0 - nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi] == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        
                        ans.push_back(temp);
                        
                        while(lo<hi && nums[lo] == nums[lo+1])
                            lo++;
                        while(lo<hi && nums[hi] == nums[hi-1])
                            hi--;
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return ans;
    }
};
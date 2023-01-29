// GFG Solution:

// class Solution {
// public:
//     vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
//         // Effective soln using Bit Manipulation.
//         int n = nums.size();
//         vector<vector<int>> res;

//         for(int i = 0; i<(1<<n); i++){
//             vector<int> ans;
//             for(int j = 0; j<n; j++){
//                 if(i & (1<<j))
//                     ans.push_back(nums[j]);
//             }
//             res.push_back(ans);
//         }
//         return res;
//     }
// };

// LeetCode Solution:

class Solution {
public:
    void printUniqueSubsets(vector<int>& nums, set<vector<int>> &st) {
        // Effective soln using Bit Manipulation.
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i<(1<<n); i++){
            vector<int> ans;
            for(int j = 0; j<n; j++){
                if(i & (1<<j))
                    ans.push_back(nums[j]);
            }
            sort(ans.begin(), ans.end());
            st.insert(ans);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> res;
        printUniqueSubsets(nums, st);
        for(auto i:st)
            res.push_back(i);
        
        return res;
    }
};
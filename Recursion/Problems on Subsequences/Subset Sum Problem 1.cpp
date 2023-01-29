class Solution{
public:
    void subsets(vector<int>& nums, vector<int> &sumv) {
        int n = nums.size();
        vector<vector<int>> res;

        for(int i = 0; i<(1<<n); i++){
            vector<int> ans;
            int sum = 0;
            for(int j = 0; j<n; j++){
                if(i & (1<<j))
                    ans.push_back(nums[j]);
            }
            for(int j:ans)
                sum+=j;
            sumv.push_back(sum);
        }
    }
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> sumv;
        subsets(arr, sumv);
        return sumv;
    }
};
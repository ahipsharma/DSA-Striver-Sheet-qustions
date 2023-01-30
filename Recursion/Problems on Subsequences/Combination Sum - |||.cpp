class Solution {
  public:
    void f(int idx, int k, int sum, vector<int> &temp, vector<vector<int>> &ans){
        
        if(k <= 0){
            if(sum == 0)
                ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i<=9; i++){
            temp.push_back(i);
            f(i+1, k-1, sum - i, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1, k, n, temp, ans);
        
        return ans;
        
    }
};
class Solution {
public:
    void f(int idx, int x, vector<int> &ds, vector<vector<int>> &ans, vector<int>& arr){
        if(x == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = idx; i<arr.size(); i++){
            if(i>idx && arr[i] == arr[i-1]) continue;
            if(arr[i]>x) break;

            ds.push_back(arr[i]);
            f(i+1, x-arr[i], ds, ans, arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int x) {
        sort(arr.begin(), arr.end());
        vector<int> ds;
        vector<vector<int>> ans;
        f(0, x, ds, ans, arr);
        return ans;
    }
};
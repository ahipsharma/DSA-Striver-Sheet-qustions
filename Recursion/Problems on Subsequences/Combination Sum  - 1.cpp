class Solution {
public:
    void f(int idx, int x, vector<int> v, vector<int>& arr, vector<vector<int>> &res){
        if(idx == arr.size()){
            if(x == 0) res.push_back(v);
            return;
        }
        if(arr[idx] <= x){
            v.push_back(arr[idx]);
            f(idx, x-arr[idx], v, arr, res);
            v.pop_back();
        }
        f(idx + 1, x, v, arr, res);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int x) {
        vector<vector<int>> res;
        vector<int> v;
        f(0, x, v, arr, res);

        return res;
    }
};
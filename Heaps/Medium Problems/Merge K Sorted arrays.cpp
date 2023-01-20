class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<int> ans;
        for(int i = 0;i<arr.size();i++)
            for(int j = 0;j<arr[i].size();j++)
                minh.push(arr[i][j]);
        
        while(minh.size()>0){
            int it = minh.top();
            ans.push_back(it);
            minh.pop();
        }
        return ans;
    }
};
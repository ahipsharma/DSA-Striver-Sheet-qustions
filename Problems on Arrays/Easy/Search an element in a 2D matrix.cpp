class Solution {
public:
    int binarySearch(vector<int> arr, int x, int n){
        int l = 0, h = n-1;
        while(l <= h){
            int m = (h + l)/2;
            if(arr[m] == x)
                return m;
            if(arr[m] < x)
                l = m + 1;
            if(arr[m] > x)
                h = m - 1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        for(int i = 0;i<mat.size();i++){
            int idx = binarySearch(mat[i], x, mat[i].size());
            if(idx != -1)
                return true;
        }
        return false;
    }
};
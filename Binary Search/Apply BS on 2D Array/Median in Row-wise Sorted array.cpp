class Solution{   
public:
    int median(vector<vector<int>> &mat, int R, int C){
        vector<int> res;
        for(int i = 0; i<R; i++){
            for(int j=0; j<C; j++){
                res.push_back(mat[i][j]);
            }
        }
        int n = res.size(), m = 0;
        sort(res.begin(), res.end());
        if(n%2 == 0)
            m = (res[(n/2)-1] + res[n/2])/2;
        else
            m = res[n/2];
        return m;
    }
};

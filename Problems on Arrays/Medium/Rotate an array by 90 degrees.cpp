class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        //Strategy:
        //Transpose the matrix
        //Reverse every row of the matrix to get the desired output
        int n = m.size();
        for(int i = 0; i < n;i++){
            for(int j = 0; j < i; j++){
                int t = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = t;
            }
        }
        for(int i = 0; i < n; i++){
            reverse(m[i].begin(),m[i].end());
        }
    }
};
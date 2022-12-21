class Solution{
public:
    
	int rowWithMax1s(vector<vector<int>> mat, int n, int m) {
	    int rowIndex = -1;
        int maxCount = 0;
         
        for(int i = 0; i<n; i++){
            int count = 0 ;
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            if(count > maxCount){
                maxCount = count;
                rowIndex = i;
            }
        }
        return rowIndex;
	}

};
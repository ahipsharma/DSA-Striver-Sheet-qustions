class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr){
	    int n = arr.size();
        if (n <= 1) return n;
        
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);
        
        // finding the length of LIS ending at i
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j])
                    lis[i] = max(lis[i], lis[j]+1);
            }
        }
        
        // finding the length of LDS ending at i
        for (int i = n-2; i >= 0; i--) {
            for (int j = n-1; j > i; j--) {
                if (arr[i] > arr[j])
                    lds[i] = max(lds[i], lds[j]+1);
            }
        }
        
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, lis[i] + lds[i] - 1);
        }
	    return maxLen;
	}
};
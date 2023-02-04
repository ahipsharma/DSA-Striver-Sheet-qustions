class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        int i=0, j=0;
        vector<int> ans;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        if(i<n){
            for(int k = i;k<n;k++) ans.push_back(arr1[k]);
        }
        if(j<m)
            for(int k = j;k<m;k++) ans.push_back(arr2[k]);
        return ans[k-1];
    }
};
class Solution{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]){
        vector<int> arr;
        arr.push_back(a[0]);
        for(int i=1; i<n; i++){
            if(a[i]>arr.back())
                arr.push_back(a[i]);
            else{
                int ind = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin();
                arr[ind]=a[i];
            }
        }
        return arr.size();
    }
};
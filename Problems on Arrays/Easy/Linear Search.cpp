class Solution{
    public:
    int searchInSorted(int arr[], int n, int k) {
       // Your code here
       for(int i = 0;i<n;i++){
           if(arr[i] == k)
                return 1;
       }
       return -1;
    }
};
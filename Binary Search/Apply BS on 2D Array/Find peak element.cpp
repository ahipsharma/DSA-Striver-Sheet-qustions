class Solution{
    public:
    int peakElement(int arr[], int n){
        int low=0, high = n-1;
        while(low<=high){
            int mid = (high + low)/2;
            if(mid == n-1 && arr[mid-1] < arr[mid]) return n-1;
            else if(mid == 0 && arr[mid+1] < arr[mid])return 0;
            else if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid] < arr[mid+1]) low = mid+1;
            else high = mid-1;
        }
    }
};
class Solution{
public:
    int findMin(int arr[], int n){
        int mini = arr[0];
        for(int i=1 ;i<n; i++){
            if(mini > arr[i]){
                mini = arr[i];
            }
        }
        return mini;
    }
};
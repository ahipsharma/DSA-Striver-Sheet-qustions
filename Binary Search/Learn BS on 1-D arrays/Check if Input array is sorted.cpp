class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        if(n == 1)
            return true;
        int diff = 0, i = 0, j = 1;
        while(i<j && j<n){
            diff = arr[j] - arr[i];
            i++;
            j++;
            if(diff < 0)
                return false;
        }
        return true;
    }
};
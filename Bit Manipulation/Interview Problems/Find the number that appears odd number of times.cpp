class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        int s = 0;
        for(int i = 0;i<n;i++)
            s = s^arr[i];
        return s;
    }
};
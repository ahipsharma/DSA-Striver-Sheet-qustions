// Largest Sum Subarray of Size at least K

#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int nums[n];
        for(int i=0; i<n; i++)
            cin>>nums[i];
        Solution ob;
        cout<<ob.largestSumSubarray(nums, n, k)<<endl;
    }
    return 0;
}

class Solution{
    public:
    int largestSumSubarray(int a[], int n, int k){
        int sum = 0, maxSum = INT_MIN;
        for(int i=0; i<k; i++)
            sum += a[i];
        maxSum = max(maxSum, sum);
        for(int i=k; i<n; i++){
            sum += a[i] - a[i-k];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    } 
};

// Problem: Given an array of n distinct integers sorted in ascending order, find the K-th missing number starting from the leftmost number of the array.

// Input: arr[] = {2, 3, 4, 7, 11}, K = 5

// Output: 9

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin>>nums[i];
        Solution ob;
        cout<<ob.KthMissingElement(nums, k)<<endl;
    }
    return 0;
}

int KthMissingElement(int a[], int n, int k){
    vector<int> ans;
    for(int i=1;i<n;i++){
        if((a[i]-a[i-1])>1) {
            for(int l=a[i-1]+1;l<a[i];l++) ans.push_back(l);
        }
    }
    if(k>ans.size()) return -1;
    return ans[k-1];
}
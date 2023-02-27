
// Given two sorted arrays A and B of size N and M respectively. Find the median of the two sorted arrays.

// Approach: Merge the two arrays and find the median

// Time Complexity: O(n+m)

// Space Complexity: O(n+m)

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> nums1(n), nums2(m);
        for(int i=0; i<n; i++)
            cin>>nums1[i];
        for(int i=0; i<m; i++)
            cin>>nums2[i];
        Solution ob;
        cout<<ob.MedianOfArrays(nums1, nums2)<<endl;
    }
    return 0;
}

class Solution{
    public:
    void mergeSort(vector<int>& nums1, vector<int>& nums2, vector<int> &res){
        int i = 0, j = 0, k = 0;
        while(i<nums1.size() && j <nums2.size()){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i]);
                i++;
                k++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
                k++;
            }
        }
        if(i<nums1.size()){
            while(i<nums1.size()){
                res.push_back(nums1[i]);
                i++;
            }
        }
        if(j<nums2.size()){
            while(j<nums2.size()){
                res.push_back(nums2[j]);
                j++;
            }
        }
    }
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        mergeSort(nums1, nums2, res);
        double median;
        int len = res.size();
        if (len % 2 != 0)
        return (double)res[len / 2];
 
        return (double)(res[(len - 1) / 2] + res[len / 2]) / 2.0;
        
        // return median;
    }
};
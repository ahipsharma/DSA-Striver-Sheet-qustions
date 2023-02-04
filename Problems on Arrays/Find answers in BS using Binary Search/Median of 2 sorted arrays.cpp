class Solution {
private:
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
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
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
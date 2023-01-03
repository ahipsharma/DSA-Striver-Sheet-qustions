class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Brute Force approach:

        // int maxi = INT_MIN, idx = -1;
        // if(nums.size() == 1)
        //     return 0;
        // for(int i = 0;i<nums.size();i++){
        //     if(nums[i]>maxi){
        //         maxi = max(nums[i], maxi);
        //         idx = i;
        //     }
        // }
        
        // Optimised approach:
        // Binary Search:-

        int low = 0, high = nums.size()-1, n = nums.size();

        while(low<=high){
            int mid = low + (high - low) / 2;

            if((mid==0||nums[mid-1]<nums[mid])&&(mid==n-1||nums[mid]>nums[mid+1]))
                return mid;
            else
                if(nums[mid+1] > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
        }
        return 0;
    }
};
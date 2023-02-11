class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int h, int x){
        while(l<=h){
            int mid = l + (h - l)/2;
            if(nums[mid]==x)
                return mid;
            if(nums[l] <= nums[mid])
                if(x >= nums[l] && x<nums[mid]) h = mid-1;
                else l = mid+1;
            else
                if(x>nums[mid] && x <=nums[h]) l = mid+1;
                else h = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //Strategy:
        //Binary Search is applied only to sorted array here the array is twisted.
        //So the Binary search is applied in a different way.
        //First we search if the element is in the left sorted subarray.
        //Else it will be in right sorted subarray;
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};
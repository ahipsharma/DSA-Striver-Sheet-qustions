class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //Strategy
        //2 Binary Searches for finding the positions.
        vector<int> num;
        int start = 0, end = nums.size()-1, mid;
        int l = -1, r = -1;
        while(start<=end and start>=0 and end>=0) {
            mid = start + (end-start)/2;
            if(nums[mid] == target) {
                l = mid;
                end = mid - 1;
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        start = l, end = nums.size()-1;
        while(start<=end and start>=0 and end>=0) {
            mid = start + (end-start)/2;
            if(nums[mid] == target) {
                r = mid;
                start = mid + 1;
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        num.push_back(l);
        num.push_back(r);
        return num;
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // This based upon the three way sorting technique.
        // Three pointers: low, mid, high;
        // All the elements to the left of low are 0's, right of high are 2's.
        // If number at mid index is 0 => Swap (nums[low], nums[mid]), low++, mid++
        // If number at mid = 1 => mid++;
        // If the number at high = 2 => swap(nums[mid], nums[high--]);

        // Implement:

        int low = 0, mid = 0, high = nums.size()-1;

        while(mid<=high){
            switch(nums[mid]){
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};
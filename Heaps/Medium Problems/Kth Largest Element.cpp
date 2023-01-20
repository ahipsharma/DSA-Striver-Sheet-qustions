class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for(auto it:nums){
            minh.push(it);
            if(minh.size()>k)
                minh.pop();
        }
        return minh.top();
    }
};
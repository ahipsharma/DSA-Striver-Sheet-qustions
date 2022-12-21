class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Naive O(3N) approach:

        // vector<int> pos;
        // vector<int> neg;
        // vector<int> res;
        // for(int i:nums){
        //     if(i>0) pos.push_back(i);
        //     else neg.push_back(i);
        // }
        // int p = 0, n = 0;
        // for(int i = 0;i<nums.size();i++){
        //     if(i%2 == 0 && p < pos.size()){
        //         res.push_back(pos[p]);
        //         p++;
        //     }
        //     if(i%2 != 0 && n < neg.size()){
        //         res.push_back(neg[n]);
        //         n++;
        //     }
        // }
        // return res;


        // Optimized approach:

        int pos = 0, neg = 1, n = nums.size();
        vector<int> ans(n);

        for(int i:nums){
            if(i<0){
                ans[neg] = i;
                neg += 2;
            }
            else{
                ans[pos] = i;
                pos += 2;
            }
        }
        return ans;
    }
};
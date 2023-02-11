class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n=nums.size(), zcount = 0, prod=1;

        for(int i:nums){
            if(i == 0) zcount++;
            else prod *= i;
        }
        
        if(zcount == 0)
            for(int i:nums)
                res.push_back(prod/i);
        else if(zcount == 1)
            for(int i:nums)
                if(i != 0)  
                    res.push_back(0);
                else
                    res.push_back(prod);
        else
            for(int i:nums) 
                res.push_back(0);
        
        return res;
    }
};
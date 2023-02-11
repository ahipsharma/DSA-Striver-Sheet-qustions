class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int count=0, j=-1, ans=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0)
                count++;
            
            while(count>k){
                j++;
                if(arr[j] == 0)
                    count--;
            }
            int len = i-j;
            ans=max(ans, len);
        }
        return ans;
    }
};
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        int gd = greed.size(), s = sz.size();
        sort(greed.begin(), greed.end());
        sort(sz.begin(), sz.end());
        int c = 0, i = 0, j = 0;
        while(i<gd && j<s){
            if(greed[i]<=sz[j]){
                c++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return c;
    }
};
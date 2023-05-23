// Normal LIS problem.
// Just call the LIS function and check if it is equal to the length of the string s.
// If yes, then return true else false.

class Solution {
public:
    int LIS(int i, int j, string s, string t){
        if(i==0 || j==0)
            return 0;
        
        if(s[i-1] == t[j-1])
            return 1 + LIS(i-1, j-1, s, t);
        else
            return LIS(i, j-1, s, t);
    }
    bool isSubsequence(string s, string t) {
        int i = s.length(), j = t.length();
        
        if(i>j){
            return false;
        }
        else if(LIS(i, j, s, t) == i){
            return true;
        }
        else{
            return false;
        }
    }
};
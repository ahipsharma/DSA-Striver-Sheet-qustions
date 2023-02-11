class Solution{
    public:
    int longestUniqueSubsttr(string s){
        // set<char> st;
        
        // if(s.length() == 0)
        //     return 0;
        
        // int j=0, maxLen=INT_MIN;
        // for(int i=0; i<s.length(); i++){
        //     if(st.find(s[i]) != st.end()){
        //         while(j<i && st.find(s[i]) != st.end()){
        //             st.erase(s[j]);
        //             j++;
        //         }
        //     }
        //     st.insert(s[i]);
        //     maxLen=max(maxLen, (i-j+1));
        // }
        // return maxLen;
        
        // Optimized:
        
        int left=0,right=0, len=0, n=s.size();

        vector<int>m(256,-1);

        while(right<n){
            if(m[s[right]]!=-1)
                left=max(m[s[right]]+1,left);
            m[s[right]]=right;

            len=max(len,right-left+1);

            right++;
        }
        return len;
    }
};
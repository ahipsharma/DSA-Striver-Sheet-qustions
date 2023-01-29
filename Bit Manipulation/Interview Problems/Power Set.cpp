class Solution{
	public:
	void gen(int i, vector<string>& ans, string s, string temp, int n){
	    if(temp.size()!=0)
	        ans.push_back(temp);
       for(int ind=i; ind<n; ind++)
            gen(ind+1, ans, s, temp+s[ind], n);
    }
    vector<string> AllPossibleStrings(string s){        
        vector<string> ans;
        gen(0, ans, s, "", s.size());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
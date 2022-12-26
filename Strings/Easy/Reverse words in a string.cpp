class Solution {
public:
    string reverseWords(string &s) {
        vector<string> res;
        stringstream strs(s);
        string word;
        while(strs>>word)
            res.push_back(word);
        
        for(int i = res.size() - 2;i>=0;i--){
            word.append(" ");
            word.append(res[i]);
        }
        return word;
    }
};
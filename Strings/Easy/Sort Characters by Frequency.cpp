class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto i:s)
            freq[i]++;
        priority_queue<pair<int, char>> q;
        for (auto [a, frq] : freq) 
            q.push({frq, a});
        
        string res;
        pair<int,char> curr;
        while (!q.empty()) {
            curr = q.top();
            q.pop();
            res += string(curr.first, curr.second);
        }
        
        return res;
    }
};
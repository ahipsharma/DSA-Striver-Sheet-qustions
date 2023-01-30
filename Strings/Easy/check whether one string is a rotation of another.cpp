class Solution {
public:
    bool rotateString(string s, string e) {
        return (s.length() == e.length() && (s+s).find(e) != string::npos);
    }
};
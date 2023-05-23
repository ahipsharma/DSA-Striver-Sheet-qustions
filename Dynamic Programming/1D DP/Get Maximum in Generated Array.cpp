// It's a general Array Question, Easiest Dp solution.

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        vector<int> res(n+1);
        int m = INT_MIN;
        res[0] = 0, res[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2 != 0) res[i] = res[i / 2] + res[i / 2 + 1];
            else res[i] = res[i / 2];
            m = max(res[i], m);
        }
        return m;
    }
};
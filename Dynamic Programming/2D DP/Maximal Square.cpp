// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area using recursion.

#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    if (n == 0) return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxLen = 0;
    for (int i = 0; i < m; i++) {
        dp[i][0] = matrix[i][0] - '0';
        maxLen = max(maxLen, dp[i][0]);
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j] - '0';
        maxLen = max(maxLen, dp[0][j]);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    return maxLen * maxLen;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << maximalSquare(matrix) << endl;
    return 0;
}
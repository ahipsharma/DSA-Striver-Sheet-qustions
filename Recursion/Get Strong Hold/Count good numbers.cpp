// Given two positive integers L, R and a digit D, find out all the good numbers in the range [L, R], which do not contain the digit D.
// A number is a good number if it's every digit is larger than the sum of digits which are on the right side of that digit.
// Use Recursion

#include <iostream>
using namespace std;

int countGoodNumbers(int L, int R, int D) {
    if (L > R) return 0;
    if (L == R) {
        int num = L;
        int sum = 0;
        while (num) {
            int r = num % 10;
            if (r == D) return 0;
            if (r < sum) return 0;
            sum += r;
            num /= 10;
        }
        return 1;
    }
    int mid = (L + R) / 2;
    return countGoodNumbers(L, mid, D) + countGoodNumbers(mid + 1, R, D);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        cout << countGoodNumbers(L, R, D) << endl;
    }
    return 0;
}
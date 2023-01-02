class Solution{
  public:
    long long int floorSqrt(long long int x) {
        long long int start = 0, end = x, mid, ans;
        
        while (start <= end) {
            mid = (start + end)/2;
            if (mid * mid == x){
                ans = mid;
                break;
            }
            if (mid * mid < x){
                start = mid + 1;
                ans = mid;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};
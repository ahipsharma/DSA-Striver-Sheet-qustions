class Solution{
  public:
    int findFloor(vector<long long> v, long long n, long long x){
        int low = 0, high = n-1;
        if(x < v[0])
            return -1;
        while(low<high){
            int mid = (low + high)/2;
            if(v[mid] == x)
                return mid;
            if(v[mid] > x)
                high = mid - 1;
            if(v[mid] < x)
                low = mid + 1;
        }
        return high;
    }
};
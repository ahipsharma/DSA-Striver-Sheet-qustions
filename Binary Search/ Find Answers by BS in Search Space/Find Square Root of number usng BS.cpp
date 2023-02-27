// Find square root using Binary Search

#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.floorSqrt(n)<<endl;
    }
    return 0;
}

class Solution{
  public:
    long long int floorSqrt(long long int x) {
        int start = 1,end = x;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid <= x/mid) start = mid+1;
            else end=mid-1;
        }
        return end;
    }
};
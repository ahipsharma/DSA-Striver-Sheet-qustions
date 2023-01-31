class Solution{
public:	
	int findKRotation(int num[], int n) {
	    // code here
	    int start=0,end=n-1;
        while (start<end) {
            if (num[start]<num[end])
                return start;
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return start;
	}
};
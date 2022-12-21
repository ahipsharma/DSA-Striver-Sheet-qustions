class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int i, first, second;
        if (n < 2) {
            return 0;
        }
        // sort the array
        sort(arr, arr + n);
        // start from second last element as the largest element
        // is at last
        for (i = n - 2; i >= 0; i--) {
            // if the element is not equal to largest element
            if (arr[i] != arr[n - 1]) {
                
                return arr[i];
            }
        }
	}
};
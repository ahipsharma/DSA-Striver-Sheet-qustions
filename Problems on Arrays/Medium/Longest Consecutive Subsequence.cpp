class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int n){
        unordered_set<int> s;
        for (int i=0; i<n; i++) {
            s.insert(arr[i]);
        }
        
        int longest = 0;
        for (int i=0; i<n; i++) {
            if (s.count(arr[i] - 1) == 0) {
                int current = arr[i];
                int length = 1;
                while (s.count(current + 1)) {
                    current += 1;
                    length += 1;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
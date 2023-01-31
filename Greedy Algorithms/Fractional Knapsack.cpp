static bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}


class Solution{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, struct Item arr[], int N)
    {
    // Sorting Item on basis of ratio
        sort(arr, arr + N, cmp);
     
        double finalvalue = 0.0;
     
        // Looping through all items
        for (int i = 0; i < N; i++) {
             
            // If adding Item won't overflow,
            // add it completely
            if (arr[i].weight <= W) {
                W -= arr[i].weight;
                finalvalue += arr[i].value;
            }
     
            // If we can't add current Item,
            // add fractional part of it
            else {
                finalvalue
                    += arr[i].value
                       * ((double)W / (double)arr[i].weight);
                break;
            }
        }
    return finalvalue;
    }
};
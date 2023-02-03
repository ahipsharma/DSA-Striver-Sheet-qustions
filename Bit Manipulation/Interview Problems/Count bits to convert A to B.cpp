class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int flipped = (a^b), count = 0;
        while(flipped != 0){
            int rsb = (flipped & -flipped);
            flipped -= rsb;
            count++;
        }
        return count;
    }
};
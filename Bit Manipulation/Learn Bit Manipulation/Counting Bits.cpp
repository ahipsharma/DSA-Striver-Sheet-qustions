class Solution{
    public:
    int countSetBits(int n){
        // int sum = 0, c;
        // for(int i = 0; i<=n; i++){
        //     int a = i, c = 0;
        //     while(a){
        //         a &= (a-1);
        //         c++;
        //     }
        //     sum += c;
        // }
        // return sum;
        
        // Optimized:
        if(n == 0)
            return 0;
        int power = largestPowerOf2InRange(n);
        int bitstill2x = (1 << (power-1)) * power;
        int msb = n - (1<<(power)) + 1;
        int rest = n - (1<<power);
        
        int totBits = bitstill2x + msb + countSetBits(rest);
        return totBits;
    }
    int largestPowerOf2InRange(int n){
        int x = 0;
        while((1<<x) <= n){
            x++;
        }
        return x-1;
    }
};
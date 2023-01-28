class Solution
{
    public:
    bool checkKthBit(int n, int k){
        return n&(1<<k);
    }
};
class Solution {
  public:
    bool isPossible(vector<int> &piles, int h, int sp){
        int time = 0;
        for(auto i:piles){
            time += ceil((1.0*i)/sp);
        }
        
        return time <= h;
    }
    
    int Solve(int n, vector<int>& piles, int h) {
        int lo = 0, hi = INT_MAX, speed;
        // Here lo and high do not represent the indices, instead represent the min and max speed of eating bananas per hour.
        while(lo <= hi){
            int sp = lo + (hi - lo)/2;
            if(isPossible(piles, h, sp)){
                speed = sp;
                hi = sp-1;
            }
            else
                lo = sp+1;
        }
        return speed;
    }
};
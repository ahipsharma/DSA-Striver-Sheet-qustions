class Solution{
	public:
	bool isPrime(int n){
        // Corner cases
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
     
        return true;
    }
	vector<int> AllPrimeFactors(int n) {
	    vector<int> res;
	    for(int i = 1;i<=n; i++){
	        if(n%i == 0 && isPrime(i))
	            res.push_back(i);
	    }
	    return res;
	}
};
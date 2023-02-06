class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr, int n){
        vector<int> ans;
        map<int,int> mp;
    	int temp = 1;
    	int brr[n];
    	for (int i = 0; i < n; i++) {
    		brr[i] = arr[i];
    	}
    	sort(brr, brr + n);
    	for (int i = 0; i < n; i++) {
    		//if element is previously not store in the map
    		if (mp[brr[i]] == 0) {
    			mp[brr[i]] = temp;
    			temp++;
    		}
    	}
    	for (int i = 0; i < n; i++) {
    		ans.push_back(mp[arr[i]]);
    	}
        return ans;
    }
};
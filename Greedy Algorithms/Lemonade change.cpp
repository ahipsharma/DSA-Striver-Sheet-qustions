class Solution{ 
    public:
    bool lemonadeChange(vector<int>& bills){
		int stock5=0,stock10=0;
		for(auto i:bills){
            if(i == 5)
                stock5++;
            else if(i == 10){
                if(stock5<1)
                    return false;
                stock5--;
                stock10++;
            }
            else{
                if(stock5==0 || (stock10==0 && stock5<3))
					return false;
				else if(stock10>0){
					stock10--;
					stock5--;
				}
				else
					stock5-=3;
            }
        }
        return true;
	}
};
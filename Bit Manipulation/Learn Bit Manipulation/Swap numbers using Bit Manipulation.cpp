class Solution{   
public:
    pair<int, int> get(int a, int b){
        a = a^b;
        b = a^b;
        a = a^b;
        pair<int, int> p;
        p.first = a;
        p.second = b;
        return p;
    }
};
class Solution{
public:
    void print(int k, string s){
        if(k == 0){
            cout<<s<<" ";
            return;
        }
        
        if(s.back() == '0'){
            string s1 = s;
            s1.push_back('0');
            string s2 = s;
            s2.push_back('1');
            print(k-1, s1);
            print(k-1, s2);
        }
        if(s.back() == '1'){
            string s1 = s;
            s1.push_back('0');
            print(k-1, s1);
        }
    }
    void generateBinaryStrings(int& n){
        string s1 = "0";
        print(n-1, s1);
        string s2 = "1";
        print(n-1, s2);
    }
};
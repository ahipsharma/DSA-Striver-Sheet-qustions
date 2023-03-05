// Implement Atoi

#include <iostream>
#include <string>
using namespace std;

class Solution{
  public:
    int atoi(string s) {
        int n = s.length();
        int ans=0;
        int i=0;
        bool flag=false;
        if(s[0]=='-'){
            flag=true;
            i++;
        }
        for(;i<n;i++){
            if(s[i]<'0' or s[i]>'9') return -1;
            int r = s[i]-'0';
            ans = ans*10 + r;
        }
        if(flag) ans *= -1;
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.atoi(s)<<endl;
    }
    return 0;
}
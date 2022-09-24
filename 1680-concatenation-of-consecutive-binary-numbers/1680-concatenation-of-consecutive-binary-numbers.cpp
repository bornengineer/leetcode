/*class Solution {
public:
    long long mod = 1000000007;
    // void rev(string &res, int s, int e){
    //     while(s<e){
    //         swap(res[s], res[e]);
    //         s++;
    //         e--;
    //     }
    // }
    
    string toBinary(int n){
        string res = "";
        while(n>0){
            res += to_string(n % 2);
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    int concatenatedBinary(int n) {
        string s = "";
        for(int i = 1; i<= n; i++){
            s += toBinary(i);
        }
        // cout<<s;
        long long  ans = 0;
        int j = s.size()-1;
        long long power = 1;
        while(j >= 0){
            long long temp = (s[j] - '0') * power;
            power *= 2;
            power %= mod;
            ans += temp%mod;
            j--;
        }
        return ans%mod;
    }
};*/


#define mod 1000000007
class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 0, len = 0;
        for(int i = 1; i<=n; i++){
            
            if((i & (i-1)) == 0)len++;
            
            res = (res<<len)%mod;
            res += i % mod;
        }
        return res;
    }
};
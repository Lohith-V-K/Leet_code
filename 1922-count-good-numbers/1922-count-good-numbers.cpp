class Solution {
public:
int mod=1e9+7;
    long long modpower(long long base,long long exponent)
    {
        long long res=1;
        base=base%mod;
        while(exponent>0)
        {
            if(exponent%2==1)
            {
                res=(res*base)%mod;
            }
            base=(base*base)%mod;
            exponent/=2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long evenways=modpower(5,even);
        long long oddways=modpower(4,odd);
        return (evenways*oddways)%mod;
    }
};

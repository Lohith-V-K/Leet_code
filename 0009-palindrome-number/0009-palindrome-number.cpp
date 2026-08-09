class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long digits=0;
        long long z=x;
        while(z>0)
        {
            long long rem=z%10;
            digits=digits*10+rem;
            z=z/10;
        }
        if(digits==x)return true;
        else
        return false;
        
    }
};
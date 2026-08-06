class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<n+11;i++)
        {
            int x=i;
            int prod=1;
            int dig=0;
            while(x!=0)
            {
                dig=x%10;
                prod*=dig;
                x=x/10;
            }
            if(prod%t==0)return i;
        }
        return -1;
        
    }
};
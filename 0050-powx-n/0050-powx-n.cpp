class Solution {
public:
double pow(double x,long n)
{
    if(n==0)return 1;
    if(n==1)return x;
    if(n%2==0)
    {
        return pow(x*x,n/2);
    }
    else
    {
        return x*pow(x,n-1);
    }
}
    double myPow(double x, int n) {
        if(n<0)
        {
            return(1/pow(x,-1*1LL*n));
        }
        return pow(x,n);

    }
};
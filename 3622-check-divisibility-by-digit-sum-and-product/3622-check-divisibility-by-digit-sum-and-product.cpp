class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int prod=1;
        while(temp>0)
        {
            int rem=temp%10;
            sum+=rem;
            temp=temp/10;

        }
        temp=n;
          while(temp>0)
        {
            int rem=temp%10;
            prod*=rem;
            temp=temp/10;

        }
        if(n%(prod+sum)==0)
        return true;
        else
        return false;
        
    }
};
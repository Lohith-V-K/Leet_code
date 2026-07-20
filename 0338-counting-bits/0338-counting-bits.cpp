class Solution {
public:
int countbitsl(int n)
{
    int count=0;
    while(n>0)
    {
            count=count+(n&1);
            n=n>>1;

    }
    return count;
}
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<n+1;i++)
        {
            ans[i]=countbitsl(i);
        }
        return ans;
        
    }
};
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixmax=nums[0];
        vector<int>suffmin(n);
         suffmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
           suffmin[i]=min(suffmin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            prefixmax=max(prefixmax,nums[i]);
            if(prefixmax-suffmin[i]<=k)
            return i;
        }
         return -1;
    }
   
};
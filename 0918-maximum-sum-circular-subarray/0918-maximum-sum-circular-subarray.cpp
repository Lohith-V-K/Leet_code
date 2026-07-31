class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long globalmax=INT_MIN;
        long long globalmin=INT_MAX;
        long long currmin=INT_MAX;
        long long currmax=INT_MIN;
        long long total=0;
        for(int i=0;i<nums.size();i++)
        {
            currmax=max(currmax+nums[i],1LL*nums[i]);
            currmin=min(currmin+nums[i],1LL*nums[i]);
            total+=nums[i];
            globalmax=max(globalmax,currmax);
            globalmin=min(globalmin,currmin);
            


        }
        if(globalmax<0)return globalmax;
        return max(globalmax,total-globalmin);
        
    }
};
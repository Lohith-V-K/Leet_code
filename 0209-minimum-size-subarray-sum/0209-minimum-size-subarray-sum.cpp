class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();
        int left=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum<target)return 0;
         sum=0;
        int ans=INT_MAX;
        for(int right=0;right<n;right++)
        {
            sum+=nums[right];
            while(sum>=target)
            {
                ans=min(right-left+1,ans);
                sum-=nums[left]*1LL;
                left++;
               
                }

            }
        
        return ans==INT_MAX?0:ans;
        
    }
};
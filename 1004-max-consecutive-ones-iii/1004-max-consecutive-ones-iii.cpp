class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,maxlength=0;
        int n=nums.size();
        int zeroescount=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]==0)
            {
                zeroescount++;
            }
            if(zeroescount>k)
            {
                if(nums[left]==0)
                {
                    zeroescount--;
                }
                left++;
            }
            maxlength=max(maxlength,right-left+1);
        }
        return maxlength;
        
    }
};
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1=1;
        int cnt2=1;
        int cnt1max=1;
        int cnt2max=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                cnt1++;
                cnt1max=max(cnt1max,cnt1);
            }
            else
            {
                cnt1=1;
            }
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                cnt2++;
                cnt2max=max(cnt2max,cnt2);
            }
            else
            {
                cnt2=1;
            }
        }
        return max(cnt1max,cnt2max);
    }
};
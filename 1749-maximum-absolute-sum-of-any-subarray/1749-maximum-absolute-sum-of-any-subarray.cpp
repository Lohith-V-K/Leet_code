class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res=0;
        int currsum=0;
        int maxprefix=0;
        int minprefix=0;
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            res=max(res,max(abs(currsum-minprefix),abs(currsum-maxprefix)));
            minprefix=min(minprefix,currsum);
            maxprefix=max(maxprefix,currsum);
        }
        return res;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int currsum=0;
        int res=0;
        unordered_map<int,int>prefix;
        prefix[0]=1;
        for(int i=0;i<n;i++)
        {
            currsum+=nums[i];
            int diff=currsum-k;
            res+=prefix[diff];
            prefix[currsum]++;

        }
        return res;
    }
};
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>ans;
        for(int num:nums)
        {
            mp[num]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1 && mp.find(nums[i]+1)==mp.end() && mp.find(nums[i]-1)==mp.end())
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
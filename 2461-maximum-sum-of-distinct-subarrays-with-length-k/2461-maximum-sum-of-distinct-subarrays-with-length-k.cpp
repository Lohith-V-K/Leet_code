class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        long long sum=0;
        int l=0;
        unordered_map<int,int> map;
        for(int right=0;right<n;right++)
        {
            map[nums[right]]++;
             sum+=nums[right];
            if(right-l+1>k)
            {
                map[nums[l]]=map[nums[l]]-1;
                if(map[nums[l]]==0)map.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            if(map.size()==k){
            ans=max(ans,sum);
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int k=0;
        for(int i=nums[0];i<=nums[nums.size()-1];i++)
        {
            if (!binary_search(nums.begin(), nums.end(), i)) 
                ans.push_back(i);
        }
        return ans;
        
    }
};
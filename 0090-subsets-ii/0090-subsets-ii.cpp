class Solution {
public:
    void backtrack(vector<int>&nums,vector<int>&subset,int index,vector<vector<int>>&result)
    {
        result.push_back(subset);
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])continue;
            subset.push_back(nums[i]);
            backtrack(nums,subset,i+1,result);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>result;
        vector<int>currentsubset;
        backtrack(nums,currentsubset,0,result);
        return result;
    }
};
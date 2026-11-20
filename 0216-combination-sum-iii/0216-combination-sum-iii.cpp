class Solution {
public:
    void backtrack(vector<int>&nums,vector<int>&curr,vector<vector<int>>&res,int index,int target,int valid)
    {
        if(target==0 && curr.size()==valid)
        {
            res.push_back(curr);
            return;
        }
        if(curr.size()>=valid || index>=nums.size() || nums[index]>target)
        {
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]>target)break;
            curr.push_back(nums[i]);
            backtrack(nums,curr,res,i+1,target-nums[i],valid);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums(9);
        for(int i=0;i<9;i++)
        {
            nums[i]=i+1;
        }
        vector<vector<int>>res;
        vector<int>curr;
        backtrack(nums,curr,res,0,n,k);
        return res;
    }
};
class Solution {
public:
void backtrack(vector<int> &nums,vector<int> &subset,int index,vector<vector<int>> &result)
{
    result.push_back(subset);
    for(int i=index;i<nums.size();i++)
    {
        //choose
        subset.push_back(nums[i]);
        //backtrack
        backtrack(nums,subset,i+1,result);
        //undo
        subset.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>currentsubset;
        backtrack(nums,currentsubset,0,result);
        return result;

        
    }
};
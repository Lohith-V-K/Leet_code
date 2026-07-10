class Solution {
public:
vector<vector<int>>ans;
void backtrack(vector<int> &candidates,int target,int index,vector<int> &current)
{
    if(target==0)
    {
        ans.push_back(current);
        return;
    }
    if(target<0)
    {
        return;
    }
    for(int i=index;i<candidates.size();i++)
    {
        current.push_back(candidates[i]);
       
        backtrack(candidates,target-candidates[i],i,current);
        
        current.pop_back();

    }
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<int>current;
        backtrack(candidates,target,index,current);
        return ans;
        
    }
};
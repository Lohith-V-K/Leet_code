class Solution {
public:
vector<vector<int>>ans;
void backtracking(vector<int> &candidates,int target,int index,vector<int> &current)
{
    if(target==0)
    {
        ans.push_back(current);
        return ;
    }
   
    for(int i=index;i<candidates.size();i++)
    {
        if(i>index && candidates[i]==candidates[i-1])
        {
            continue;
        }
        if(candidates[i]>target)
        {
            break;
        }
        current.push_back(candidates[i]);
        backtracking(candidates,target-candidates[i],i+1,current);
        current.pop_back();


    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>current;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,current);
        return ans;
        
    }
};
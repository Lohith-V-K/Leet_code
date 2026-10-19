class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
    vector<int>indegree(V,0);
    vector<vector<int>>adjc(V);
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<V;i++)
    {
      for(auto it:adj[i])
      {
        adjc[it].push_back(i);
        indegree[i]++;
      }
    }
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adjc[node])
        {
            indegree[it]=indegree[it]-1;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
 }
};
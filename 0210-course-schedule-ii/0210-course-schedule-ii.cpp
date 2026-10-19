class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<int>visited(v,0);
        vector<int>indegree(v,0);
        vector<vector<int>>adj(v);
        vector<int>ans;
      for(auto it:prerequisites)
      {
        int u=it[0];
        int v=it[1];
        indegree[u]++;
        adj[v].push_back(u);
      }
      queue<int>q;
      for(int i=0;i<v;i++)
      {
        if(indegree[i]==0)
        {
            visited[i]=0;
            q.push(i);
        }
      }
      while(!q.empty())
      {
        int node=q.front();
        q.pop();
        visited[node]=0;
        ans.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
      }
      if(ans.size()==v)
      {
        return ans;
      }
      else
      {
        return {};
      }

        
    }
};
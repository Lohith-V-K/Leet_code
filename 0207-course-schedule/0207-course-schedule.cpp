class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<int>visited(N,0);
        vector<int>indegree(N,0);
        vector<int>topo;
        vector<vector<int>>adj(N);
       for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                visited[i]=0;
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return (topo.size()==N);
    }
};
